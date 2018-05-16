#' BG Envelope
#'
#' Calculates the envelope (bounding box) of a geometry
#'
#' @param x
#'
#' @export
bg_envelope <- function(x, strategy = c("cartesian", "spherical","geographic")) {
  strategy <- match.arg(strategy)
  switch(
    strategy
    , "cartesian"  = rcpp_wkt_envelope_cartesian(x)
    , "spherical"  = rcpp_wkt_envelope_spherical(x)
    , "geographic" = rcpp_wkt_envelope_geographic(x)
  )
}
