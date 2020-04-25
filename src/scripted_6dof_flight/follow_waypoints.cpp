#include "follow_waypoints.h"
#include "waypoint.h"
#include "waypoint_queue.h"
#include <geometry3d/position.h>
#include <geometry3d/velocity.h>

namespace Scripted6DoFFlight
{
	FollowWaypoints::FollowWaypoints(
		const AircraftState& enteringCondition,
		const WaypointQueue& qWaypints)
		: course(qWaypints)
	{}

	AircraftState FollowWaypoints::update(double tStep, double t0, const AircraftState& currentState) const
	{

		if (course.waypointsRemaining(t0))
		{
			auto nextWaypoint = course.nextWaypoint(t0).value();

			if (nextWaypoint.arrivalTime() > tStep+t0)
			{
				Position newX = currentState.approach(nextWaypoint.position(), tStep);
				Geometry3D::Velocity newXDot = Geometry3D::Velocity::from(currentState, newX, tStep);

				Orientation newTheta = currentState.approach(nextWaypoint.orientation(), tStep);
				Geometry3D::Rotation newThetaDot = Geometry3D::Rotation::from(currentState, newTheta, tStep);

				return AircraftState(newX, newTheta, newXDot, newThetaDot);
			}
			else
			{
				// 
				AircraftState atWaypoint = FollowWaypoints::update(nextWaypoint.arrivalTime()-t0, t0, currentState); //don't think we can just jump?!
				return FollowWaypoints::update(tStep-nextWaypoint.arrivalTime(), nextWaypoint.arrivalTime(), atWaypoint);
			}
		}

		return currentState;
	}

	bool FollowWaypoints::completed() const
	{
		return false;
	}

}