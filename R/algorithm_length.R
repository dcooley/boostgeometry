#' BG Length
#'
#' Calculates the length of a geometry
#'
#' @param wkt
#' @param strategy
#'
#' @examples
#'
#' @export
bg_length <- function(wkt, strategy = c('cartesian','spherical','geographic')) {

  ## need to switch in R; variants not supported in c++
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_length_cartesian(wkt),
    "spherical"  =  rcpp_wkt_length_spherical(wkt),
    "geographic" =  rcpp_wkt_length_geographic(wkt)
    )
}
