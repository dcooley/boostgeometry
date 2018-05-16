
#ifndef R_BOOSTGEOMETRY_H
#define R_BOOSTGEOMETRY_H

#include <boost/geometry.hpp>

#include <iostream>

#include <boost/fusion/include/for_each.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/bind.hpp>
#include <boost/variant.hpp>
#include <boost/spirit/home/x3.hpp>

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

namespace boostgeometry {
  const float EARTH_RADIUS = 6371009.0;    // metres
}

//https://stackoverflow.com/questions/48040584/how-to-create-a-geometry-using-a-variant

namespace detail {
template <typename Variant> struct read_any_helper {

  static Variant call(std::string const& wkt) {
    Variant output;
    call_impl(wkt, output);
    return output;
  }

  using result_type = void;
  template <typename Geo> result_type operator()(std::string const& wkt, Geo& output) const {
    bg::read_wkt(wkt, output);
  }

private:
  template <typename... T>
  static void call_impl(std::string const& wkt, boost::variant<T...>& output) {
    static auto const switch_ = gen_switch(output);
    if (parse(wkt.begin(), wkt.end(), switch_, output)) {
      boost::apply_visitor(boost::bind(read_any_helper{}, boost::ref(wkt), _1), output);
    } else {
      throw bg::read_wkt_exception("Unregistered type", wkt);
    }
  }

  template <typename... T>
  static auto gen_switch(boost::variant<T...> const&) {
    namespace x3 = boost::spirit::x3;
    x3::symbols<Variant> result;

    boost::fusion::for_each(boost::fusion::vector<T...>{}, [&result](auto&& seed) {
      auto const serialized = boost::lexical_cast<std::string>(bg::wkt(seed));

      std::string keyword;
      if (x3::parse(serialized.begin(), serialized.end(), +x3::alpha, keyword)) {
        result.add(keyword, std::forward<decltype(seed)>(seed));
      } else {
        throw std::logic_error(std::string("registering WKT for ") + typeid(seed).name());
      }
    });
    return result;
  }
};
}

//typedef boost::tuple<double, double> generic_point;
typedef bgm::point< float, 2, bg::cs::cartesian > point_type_cartesian;
typedef bgm::point< float, 2, bg::cs::spherical_equatorial< bg::degree > > point_type_spherical;
typedef bgm::point< float, 2, bg::cs::geographic< bg::degree > > point_type_geographic;
//typedef bgm::d2::point_xy<double> point_type_d2;

/*
typedef boost::variant<
  bgm::polygon<point_type_cartesian>,
  bgm::polygon<point_type_spherical>,
  bgm::polygon<point_type_geographic>
> CSGPolygon;
*/

typedef boost::variant<
  point_type_cartesian,
  bgm::multi_point<point_type_cartesian>,
  bgm::linestring<point_type_cartesian>,
  bgm::multi_linestring<bgm::linestring<point_type_cartesian> >,
  bgm::polygon<point_type_cartesian>,
  bgm::multi_polygon<bgm::polygon<point_type_cartesian> >
> CartesianGeometry;

typedef boost::variant<
  point_type_spherical,
  bgm::multi_point<point_type_spherical>,
  bgm::linestring<point_type_spherical>,
  bgm::multi_linestring<bgm::linestring<point_type_spherical> >,
  bgm::polygon<point_type_spherical>,
  bgm::multi_polygon<bgm::polygon<point_type_spherical> >
> SphericalGeometry;

typedef boost::variant<
  point_type_geographic,
  bgm::multi_point<point_type_geographic>,
  bgm::linestring<point_type_geographic>,
  bgm::multi_linestring<bgm::linestring<point_type_geographic> >,
  bgm::polygon<point_type_geographic>,
  bgm::multi_polygon<bgm::polygon<point_type_geographic> >
> GeographicGeometry;


typedef boost::variant<
  CartesianGeometry,
  SphericalGeometry
> CSGeometry;

typedef boost::variant<
  SphericalGeometry,
  GeographicGeometry
> SGGeometry;

typedef boost::variant<
  CartesianGeometry,
  SphericalGeometry,
  GeographicGeometry
> CSGGeometry;

template <typename Variant = CartesianGeometry>
Variant read_cartesian_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalGeometry>
Variant read_spherical_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicGeometry>
Variant read_geographic_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

/*
template <typename Variant = CSGPolygon>
Variant read_csgpolygon_wkt(std::string const& wkt, int geom_type) {
  switch( geom_type ) {
  case 1:
    return read_cartesian_wkt(wkt);
  case 2:
    return read_spherical_wkt(wkt);
  case 3:
    return read_geographic_wkt(wkt);
  }
  return read_cartesian_wkt(wkt);
}
*/

template <typename Variant = CSGeometry>
Variant read_cs_wkt(std::string const& wkt, int geom_type) {
  switch( geom_type ) {
  case 1:
    return read_cartesian_wkt(wkt);
  case 2:
    return read_spherical_wkt(wkt);
  }
  return read_cartesian_wkt(wkt);
}

template <typename Variant = SGGeometry>
Variant read_sg_wkt(std::string const& wkt, int geom_type) {
  switch( geom_type ) {
  case 2:
    return read_spherical_wkt(wkt);
  case 3:
    return read_geographic_wkt(wkt);
  }
  return read_spherical_wkt(wkt);
}


template <typename Variant = CSGGeometry>
Variant read_any_wkt(std::string const& wkt, int geom_type) {
  switch( geom_type ) {
  case 1:
    return read_cartesian_wkt(wkt);
  case 2:
    return read_spherical_wkt(wkt);
  case 3:
    return read_geographic_wkt(wkt);
  }
  return read_cartesian_wkt(wkt);
}

#define BG_Unknown     0
#define BG_Cartesian   1
#define BG_Spherical   2
#define BG_Geographic  3

void make_strategy(const char* strategy, int *tp = NULL);

#endif
