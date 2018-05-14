#' BG Distance
#'
#' Calculates the distances between two sets of geometries
#'
#' @param wktFrom
#' @param wktTo if null, each element of `wktFrom` is assessed against every other element of `wktFrom`
#' @param strategy
#'
#' @return matrix
#'
#' @examples
#'
#' @export
bg_distance <- function(wktFrom, wktTo = NULL, strategy = c('cartesian','spherical','geographic')) {

  if (is.null(wktTo)) wktTo <- wktFrom

  ## need to switch in R; variants not supported in c++
  strategy <- match.arg(strategy)
  switch(
    strategy,
    "cartesian"  =  rcpp_wkt_distance_cartesian(wktFrom, wktTo),
    "spherical"  =  rcpp_wkt_distance_spherical(wktFrom, wktTo),
    "geographic" =  rcpp_wkt_distance_geographic(wktFrom, wktTo)
  )
}
