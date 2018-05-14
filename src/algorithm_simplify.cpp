#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_simplify( Rcpp::List wkt, const char* strategy, double distance) {
  Rcpp::StringVector wktSimplify( wkt.length() );

  // SIMPLIFY: cartesian / spherical / geographic
  CSGGeometry geom;
  CSGGeometry geomSimplified;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt(wkt[i], tp);
    geomSimplified = read_any_wkt( wkt[i], tp );

    std::ostringstream os;
    os << bg::simplify(geom, geomSimplified, distance);
    wktSimplify[i] = os.str();
  }
  return wktSimplify;
}
