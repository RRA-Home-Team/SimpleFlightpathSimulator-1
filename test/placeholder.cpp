#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <scripted_6dof_flight/flightpath.h>

TEST_CASE("Provisional end-to-end tests", "[placeholder]" ) {

	void* handle = loadFlightpath("waypoints.xml");

    SECTION( "report project existance" ) {
        bool projectExists = true;
        REQUIRE(projectExists);
    }

}