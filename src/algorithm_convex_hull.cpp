#include "R_boostgeometry.h"
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_convex_hull( Rcpp::List wkt ) {
  Rcpp::StringVector wktHull( wkt.length() );
  /*

  //typedef boost::tuple<double, double> point;
  typedef boost::geometry::model::polygon<point_cartesian> polygon;
  CartesianGeometry poly;

  //polygon poly;
  poly = read_cartesian_wkt("polygon((2.0 1.3, 2.4 1.7, 2.8 1.8, 3.4 1.2, 3.7 1.6,3.4 2.0, 4.1 3.0"
                              ", 5.3 2.6, 5.4 1.2, 4.9 0.8, 2.9 0.7,2.0 1.3))");

  polygon hull;
  boost::geometry::convex_hull(poly, hull);

  using boost::geometry::dsv;
  std::cout
    << "polygon: " << dsv(poly) << std::endl
    << "hull: " << dsv(hull) << std::endl
  ;

  // convex_hull: cartesian
  typedef boost::tuple<double, double> point;
  typedef bgm::polygon<point_cartesian> polygon;
  polygon hull;

  CartesianGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt(wkt[i]);
    bg::convex_hull(geom, hull);
    //std::ostringstream os;
    //os << bg::wkt(hull);
    //wktHull[i] = os.str();

  }
  */
  return wktHull;
}

