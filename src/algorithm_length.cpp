#include "R_boostgeometry.h"

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_length_haversine( Rcpp::List wkt, const char* strategy ) {
  Rcpp::NumericVector wktLength( wkt.length() );

  // length:
  CSGLine geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_line_wkt(wkt[i], tp);
    wktLength[i] = bg::area( geom );   // using default strategy
    //wktLength[i] = bg::length(geom,bg::strategy::distance::haversine<float>(boostgeometry::EARTH_RADIUS));  // providing a strategy
  }

  return wktLength;
}














