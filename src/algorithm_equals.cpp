#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

// TODO(variants not supported)

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_equals( Rcpp::List x, Rcpp::List y, const char* strategy) {
  Rcpp::LogicalMatrix wktEquals( x.length(), y.length() );

  int tp;
  make_strategy(strategy, &tp);

  bgm::polygon<point_type_cartesian> geom1;
  bgm::polygon<point_type_cartesian> geom2;

  for (size_t i = 0; i < x.length(); i++) {
    //geom1 = read_any_wkt( x[i], tp );
    bg::read_wkt( x[i], geom1 );
    for (size_t j = 0; j < y.length(); j++) {
      //geom2 = read_any_wkt( y[j], tp );
      bg::read_wkt( y[j], geom2 );
      wktEquals(i, j) = bg::equals(geom1, geom2);
    }
  }

  return wktEquals;
}
