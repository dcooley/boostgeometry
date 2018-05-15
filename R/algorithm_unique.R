#' BG Unique
#'
#' Calculates the minimal set (where duplicate consecutive points are removed) of a geometry.
#'
#' @param x
#' @param strategy
#'
#' @export
bg_unique <- function(x, strategy = c("cartesian", "spherical", "geographic")) {
  strategy <- match.arg(strategy)
  rcpp_wkt_unique(x, strategy)
}
