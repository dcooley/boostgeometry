#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

// TODO(variants not supported)

// [[Rcpp::export]]
Rcpp::LogicalVector rcpp_wkt_within( Rcpp::List x, Rcpp::List y, const char* strategy ) {
  Rcpp::LogicalVector wktWithin( x.length() );

  // return a numerical logical matrix, x by y
  int tp;
  make_strategy(strategy, &tp);

  point_type_cartesian geom1;
  bgm::polygon<point_type_cartesian> geom2;

  for (size_t i = 0; i < x.length(); i++) {
    //geom1 = read_any_wkt( x[i], tp );
    bg::read_wkt( x[i], geom1 );
    for (size_t j = 0; j < y.length(); j++) {
      //geom2 = read_any_wkt( y[j], tp2 );
      bg::read_wkt( y[j], geom2 );
      wktWithin(i, j) = bg::within(geom1, geom2);
    }
  }


  return wktWithin;
}
