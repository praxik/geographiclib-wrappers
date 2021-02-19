#pragma once

// --- GeoLib Wrapper Includes --- //
#include <geolib-wrapper/GeoLibWrapperConfig.h>

// --- GeographicLib Includes --- //
#include <GeographicLib/Geodesic.hpp>
#include <GeographicLib/GeodesicLine.hpp>
#include <GeographicLib/PolygonArea.hpp>

// --- Standard Includes --- //
#include <vector>

namespace geolibwrapper
{

class GEOLIBWRAPPER_EXPORTS Geodesic
{
public:
    ///
    static std::pair< double, double > Direct(
        double lat1, double lon1,
        double azi1, double s12 );

    ///
    static double Inverse(
        double lat1, double lon1,
        double lat2, double lon2 );

    ///
    static double Inverse(
        double lat1, double lon1,
        double lat2, double lon2,
        double& azi1, double& azi2 );

    ///
    static GeographicLib::GeodesicLine InverseLine(
        double lat1, double lon1,
        double lat2, double lon2 );

    ///
    static void PerimeterArea(
        std::vector< std::pair< double, double > > const& latlons,
        double& perimeter,
        double& area );

private:
    ///
    Geodesic() = delete;
    Geodesic( Geodesic const& ) = delete;
    Geodesic& operator =( Geodesic const& ) = delete;

    static GeographicLib::Geodesic const& s_geod;
};

} //end geolibwrapper
