#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


void simplify_geometry( Rcpp::List& wkt, Rcpp::List& wktSimplified ) {

}


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_simplify( Rcpp::List wkt, const char* strategy, double distance) {
  Rcpp::StringVector wktSimplify( wkt.length() );

  // SIMPLIFY: cartesian / spherical / geographic
  // POINT/MULTIPOINT/LINESTRING/POLYGON
  //bgm::linestring<point_type_cartesian> geom;
  //bgm::multi_linestring<point_type_cartesian> geom;

//  bgm::multi_point<point_type_cartesian> geom;
//  bgm::multi_point<point_type_cartesian> geomSimplified;

//  bgm::multi_linestring<bgm::linestring<point_type_cartesian> > geom;
//  bgm::multi_linestring<bgm::linestring<point_type_cartesian> > geomSimplified;

  //bgm::multi_polygon<bgm::polygon<point_type_geographic> > geom;
  //bgm::multi_polygon<bgm::polygon<point_type_geographic> > geomSimplified;

  CartesianGeometry geom;
  CartesianGeometry geomSimplified;

  //CSGeometry geom;
  //CSGeometry geomSimplified;


  //bgm::multi_linestring<point_type_cartesian> geomSimplified;
  //SimpleCartesianGeometry geom;
  //SimpleCartesianGeometry geomSimplified;
  int tp;
  make_strategy(strategy, &tp);
  std::ostringstream os;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    //geom = read_cs_wkt( wkt[i], tp );

    //std::ostringstream os;
    bg::simplify(geom, geomSimplified, distance);
    std::cout << bg::wkt( geomSimplified ) << std::endl;
    //os << bg::wkt(geomSimplified);
    //wktSimplify[i] = os.str();
  }

  return wktSimplify;
}
