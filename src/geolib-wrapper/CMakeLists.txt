file( GLOB HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.h" )
file( GLOB SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*.cpp" )

set( TARGET_NAME geolibwrapper )
set( TARGET_VERSION ${${CMAKE_PROJECT_NAME}_VERSION} )
set( TARGET_EXPORT ${CMAKE_PROJECT_NAME}Targets )
set( TARGET_CATEGORY Lib )
set( PRIVATE_HEADERS ${HEADERS} )
set( PUBLIC_HEADERS ${HEADERS} )
set( PRIVATE_SOURCES ${SOURCES} )
set( INCDIR_NAME "geolib-wrapper" )

include_directories( ${CMAKE_SOURCE_DIR}/src )
include_directories( ${GeographicLib_INCLUDE_DIRS} )

add_definitions( -DGEOLIBWRAPPER_LIBRARY )

add_library( ${TARGET_NAME} SHARED ${PRIVATE_SOURCES} ${PRIVATE_HEADERS} )
target_link_libraries( ${TARGET_NAME}
  ${GeographicLib_LIBRARIES} )

include( ModuleInstall )
