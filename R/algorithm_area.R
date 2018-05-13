#' BG Area
#'
#' Calculates the area of a geometry
#'
#' @param wkt
#' @param strategy
#'
#' @examples
#'
#' @export
bg_area <- function(wkt, strategy = c('cartesian','spherical','geographic')) {
  strategy <- match.arg(strategy)
  rcpp_wkt_area(wkt, strategy)
}
