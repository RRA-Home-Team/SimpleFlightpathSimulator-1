find_path(Boost_INCLUDE_DIR
NAMES
  boost/numeric/odeint.hpp
PATHS
  ${CMAKE_SOURCE_DIR}/../boost_1_72_0
)

set(Boost_VERSION "1.72.0")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Boost
FOUND_VAR Boost_FOUND
REQUIRED_VARS
Boost_INCLUDE_DIR
)

if (Boost_FOUND AND NOT TARGET ::Boost)
  add_library(::Boost INTERFACE IMPORTED)
  set_target_properties(::Boost PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES
    ${Boost_INCLUDE_DIR}
  )
endif()

mark_as_advanced(
  Boost_INCLUDE_DIR
)
