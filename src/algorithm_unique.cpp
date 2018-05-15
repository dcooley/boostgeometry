#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_unique( Rcpp::List wkt, const char* strategy ) {
  Rcpp::StringVector wktUnique( wkt.length() );

  boost::geometry::model::polygon<point_type_cartesian> poly;
  boost::geometry::read_wkt("POLYGON((0 0,0 0,0 5,5 5,5 5,5 5,5 0,5 0,0 0,0 0,0 0,0 0))", poly);
  boost::geometry::unique(poly);
  std::cout << boost::geometry::wkt(poly) << std::endl;

  CSGGeometry geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt(wkt[i], tp);
    bg::unique( geom );
    std::ostringstream os;
    os << bg::wkt( geom );
    wktUnique[i] = os.str();
  }

  return wktUnique;
}



