#' BG Number Geometries
#'
#' Calculates the number of geometries of a geometry
#'
#' @param wkt
#'
#' @examples
#'
#' @export
bg_number_geometries <- function(wkt) rcpp_wkt_num_geometries(wkt)


#' BG Number Interior Rings
#'
#' Calculates the number of interior rings of a geometry
#'
#' @param wkt
#'
#' @examples
#'
#' @export
bg_number_interior_rings <- function(wkt) rcpp_wkt_num_interior_rings(wkt)

#' BG Number Points
#'
#' Calculates the number of points of a geometry
#'
#' @param wkt
#'
#' @examples
#'
#' @export
bg_number_points <- function(wkt) rcpp_wkt_num_points(wkt)


#' BG Number Segments
#'
#' Calculates the number of segments of a geometry
#'
#' @param wkt
#'
#' @examples
#'
#' @export
bg_number_segments <- function(wkt) rcpp_wkt_num_segments(wkt)
