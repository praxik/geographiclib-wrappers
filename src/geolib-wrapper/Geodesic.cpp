// --- GeoLib Wrapper Includes --- //
#include <geolib-wrapper/Geodesic.h>

namespace geolibwrapper
{

////////////////////////////////////////////////////////////////////////////////
GeographicLib::Geodesic const& Geodesic::s_geod = GeographicLib::Geodesic::WGS84();
////////////////////////////////////////////////////////////////////////////////
std::pair< double, double > Geodesic::Direct(
    double lat1, double lon1,
    double azi1, double s12 )
{
    double lat2, lon2;
    s_geod.Direct( lat1, lon1, azi1, s12, lat2, lon2 );
    return std::make_pair( lat2, lon2 );
}
////////////////////////////////////////////////////////////////////////////////
double Geodesic::Inverse(
    double lat1, double lon1,
    double lat2, double lon2 )
{
    double s12;
    s_geod.Inverse( lat1, lon1, lat2, lon2, s12 );
    return s12;
}
////////////////////////////////////////////////////////////////////////////////
double Geodesic::Inverse(
    double lat1, double lon1,
    double lat2, double lon2,
    double& azi1, double& azi2 )
{
    double s12;
    s_geod.Inverse( lat1, lon1, lat2, lon2, s12, azi1, azi2 );
    return s12;
}
////////////////////////////////////////////////////////////////////////////////
GeographicLib::GeodesicLine Geodesic::InverseLine(
    double lat1, double lon1,
    double lat2, double lon2 )
{
    return s_geod.InverseLine( lat1, lon1, lat2, lon2 );
}
////////////////////////////////////////////////////////////////////////////////
void Geodesic::PerimeterArea(
    std::vector< std::pair< double, double > > const& latlons,
    double& perimeter,
    double& area )
{
    using namespace GeographicLib;

    PolygonArea pa( s_geod, false );
    for( auto const& pair : latlons )
    {
        pa.AddPoint( pair.first, pair.second );
    }
    pa.Compute( false, true, perimeter, area );
    perimeter = std::fabs( perimeter );
    area = std::fabs( area );
}
////////////////////////////////////////////////////////////////////////////////

} //end geolibwrapper
