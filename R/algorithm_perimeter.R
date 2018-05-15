#' BG Perimeter
#'
#' Calculates the length of the perimeter of a geometry
#'
#' @param x
#' @param strategy
#'
#' @export
bg_perimeter <- function(x, strategy = c("cartesian", "spherical", "geographic")) {
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_perimeter_cartesian(x),
    "spherical"  =  rcpp_wkt_perimeter_spherical(x),
    "geographic" =  rcpp_wkt_perimeter_geographic(x)
  )
}
