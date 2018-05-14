#' BG Is Empty
#'
#' Checks if a geometry is empty
#'
#' @param wkt
#' @param strategy
#'
#' @examples
#'
#' @export
bg_is_empty <- function(wkt, strategy = c("cartesian", "spherical", "geographic")) {
  strategy <- match.arg(strategy)
  rcpp_wkt_is_empty(wkt, strategy)
}


#' BG Is Simple
#'
#' Checks if a geometry is simple
#'
#' @param wkt
#' @param strategy
#'
#' @examples
#'
#' @export
bg_is_simple <- function(wkt, strategy = c("cartesian", "spherical", "geographic")) {
  strategy <- match.arg(strategy)
  rcpp_wkt_is_simple(wkt, strategy)
}

#' BG Is Valid
#'
#' Checks if a geometry is valid
#'
#' @param wkt
#' @param strategy
#'
#' @examples
#'
#' @export
bg_is_valid <- function(wkt, strategy = c("cartesian", "spherical", "geographic")) {
  strategy <- match.arg(strategy)
  rcpp_wkt_is_valid(wkt, strategy)
}
