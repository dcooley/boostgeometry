#ifndef R_BOOSTGEOMETRY_DENSIFY_H
#define R_BOOSTGEOMETRY_DENSIFY_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
  //linestring_cartesian
  //, multi_linestring_cartesian
   polygon_cartesian
  //, multi_polygon_cartesian
> CartesianDensify;


typedef boost::variant<
  //linestring_spherical
  //, multi_linestring_spherical
   polygon_spherical
  //, multi_polygon_spherical
> SphericalDensify;


typedef boost::variant<
  linestring_geographic
  //, multi_linestring_geographic
  //, polygon_geographic
  //, multi_polygon_geographic
> GeographicDensify;


template <typename Variant = CartesianDensify>
Variant read_cartesian_densify_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalDensify>
Variant read_spherical_densify_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicDensify>
Variant read_geographic_densify_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif
