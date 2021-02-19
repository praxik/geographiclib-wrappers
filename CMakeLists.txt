cmake_minimum_required( VERSION 3.0.0 )
foreach( policy )
  if( POLICY ${policy} )
    cmake_policy( SET ${policy} NEW )
  endif()
endforeach()
foreach( policy
  CMP0074 # CMake 3.12
  CMP0078 # CMake 3.13
  CMP0086 # CMake 3.14
  )
  if( POLICY ${policy} )
    cmake_policy( SET ${policy} OLD )
  endif()
endforeach()

project( GEOLIBWRAPPER )

set( ${CMAKE_PROJECT_NAME}_MAJOR_VERSION 0 )
set( ${CMAKE_PROJECT_NAME}_MINOR_VERSION 1 )
set( ${CMAKE_PROJECT_NAME}_PATCH_VERSION 0 )
set( v ${CMAKE_PROJECT_NAME}_VERSION )
set( ${v} ${${CMAKE_PROJECT_NAME}_MAJOR_VERSION} )
set( ${v} ${${v}}.${${CMAKE_PROJECT_NAME}_MINOR_VERSION} )
set( ${v} ${${v}}.${${CMAKE_PROJECT_NAME}_PATCH_VERSION} )
set( v ${${v}} )
message( STATUS "Configuring ${CMAKE_PROJECT_NAME}: v${v}\n" )

set( INSTALL_LIBDIR lib )
set( INSTALL_BINDIR bin )
set( INSTALL_INCDIR include )
set( INSTALL_SHRDIR share )

if( WIN32 )
  string( REGEX REPLACE "(^| )[/-]D *NDEBUG($| )" " "
    CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" )
  string( REGEX REPLACE "(^| )[/-]D *NDEBUG($| )" " "
    CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}" )

  if( MSVC )
    if( ${CMAKE_GENERATOR} MATCHES "Win64" )
      set( VC_PLATFORM "x64" )
    else()
      set( VC_PLATFORM "Win32" )
    endif()
    message( STATUS "VC++ Platform: ${VC_PLATFORM}\n" )
  endif()
endif()

#Set a default build type if none was specified
if( NOT WIN32 AND NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Set build type" FORCE )
endif()

#Update CMake module path
set( CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/CMakeModules"
  ${CMAKE_MODULE_PATH} )

#GeographicLib
find_package( GeographicLib 1.40 )
set( GEOGRAPHICLIB_API_DEFINE "undef" )
if( GeographicLib_FOUND )
    set( GEOGRAPHICLIB_API_DEFINE "define" )
endif()

#CSharp
if( WIN32 )
  set( CSHARP_DOTNET_VERSION v4.0.30319 )
  set( CSHARP_DOTNET_VERSION ${CSHARP_DOTNET_VERSION} CACHE STRING "" FORCE )
  find_package( CSharp 4.0 )
else()
  find_package( Mono 6.12 )
endif()

#Only 64-bit...
if( CMAKE_SIZEOF_VOID_P EQUAL 8 )

#Python
find_package( PythonInterp 3 )
find_package( PythonLibs 3 )

#Ruby
find_package( Ruby 2.7 )

endif()

#Swig
find_package( SWIG 3.0.12 )

configure_file( ${PROJECT_SOURCE_DIR}/src/geolib-wrapper/GeoLibWrapperConfig.h.in
  ${PROJECT_SOURCE_DIR}/src/geolib-wrapper/GeoLibWrapperConfig.h @ONLY )

add_subdirectory( src )

set( EXPORT_LIBRARY_TARGETS
  geolibwrapper )

set( CONFIGURE_VARS
  INSTALL_LIBDIR )

include( InstallAutoDiscoveryTools )
