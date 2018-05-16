#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

//TODO(variants not supported)

/*
// [[Rcpp::export]]
Rcpp::LogicalVector rcpp_wkt_crosses( Rcpp::List wkt1, Rcpp::List wkt2, const char* strategy ) {
  Rcpp::LogicalVector wktCrosses( wkt1.length() );

  CartesianGeometry geom1;
  CartesianGeometry geom2;

  geom1 = read_cartesian_wkt( wkt1[0] );
  geom2 = read_cartesian_wkt( wkt2[0] );

  bg::crosses(geom1, geom2);

  return wktCrosses;
}
*/
