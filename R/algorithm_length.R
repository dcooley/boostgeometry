#' BG Length
#'
#' Calculates the length of a geometry
#'
#' @param x
#' @param strategy
#'
#' @examples
#'
#' @export
bg_length <- function(x, strategy = c('cartesian','spherical','geographic')) {

  ## need to switch in R; variants not supported in c++
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_length_cartesian(x),
    "spherical"  =  rcpp_wkt_length_spherical(x),
    "geographic" =  rcpp_wkt_length_geographic(x)
    )
}
