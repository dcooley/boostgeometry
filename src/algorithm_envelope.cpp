#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// TODO:
// switch on WKT seed




// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_envelope( Rcpp::List wkt, const char* strategy ) {
  Rcpp::StringVector wktEnvelope( wkt.length() );

  // TODO(variant support)
  //bgm::polygon<point_type_cartesian> geom;
  //bgm::box<point_type_cartesian> box;

  int tp;
  make_strategy(strategy, &tp);

  std::cout << "strategy type: " << tp << std::endl;

  CSGGeometry geom;
  geom = read_any_wkt( wkt[0], tp);

  if (geom.type() == typeid(GeographicGeometry)) {
    std::cout << "boost type cartesian polygon " << std::endl;
  } else {
    std::cout << "boost type isn't what I thought it was " << std::endl;
    std::cout << "it is (which) " << geom.which() << std::endl;
  }

  /*
  CSGPolygon geom;
  CSGPolygon box;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    //geom = read_any_wkt(wkt[i], tp);
    geom = read_csgpolygon_wkt( wkt[i], tp );
    //bg::read_wkt(wkt[i], geom);
    bg::envelope( geom, box );
    std::ostringstream os;
    os << bg::wkt( geom );
    wktEnvelope[i] = os.str();
  }
  */
  return wktEnvelope;
}
