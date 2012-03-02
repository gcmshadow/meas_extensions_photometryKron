#ifndef LSST_MEAS_EXTENSIONS_PHOTOMETRY_KRON_H
#define LSST_MEAS_EXTENSIONS_PHOTOMETRY_KRON_H

#include "lsst/meas/algorithms/FluxControl.h"

/**
 *  @brief C++ control object for Gaussian flux.
 *
 *  @sa GaussianFluxConfig.
 */
class KronFluxControl : public FluxControl {
public:

    LSST_CONTROL_FIELD(fixed, bool,
                       "if true, use existing shape and centroid measurements instead of fitting");
    LSST_CONTROL_FIELD(background, double, "FIXME! NEVER DOCUMENTED!");
    LSST_CONTROL_FIELD(shiftmax, double, "FIXME! NEVER DOCUMENTED!");
    LSST_CONTROL_FIELD(centroid, std::string, "name of centroid field to use if fixed is true");
    LSST_CONTROL_FIELD(shape, std::string, "name of shape field to use if fixed is true");
    LSST_CONTROL_FIELD(nSigmaForRadius, double, "Number of sigma to set Kron radius");
    LSST_CONTROL_FIELD(nRadiusForFlux, double, "Number of Kron radii for Kron flux");

    KronFluxControl() : 
        FluxControl("flux.kron"), fixed(false), background(0.0), shiftmax(10.0),
        centroid("shape.sdss.centroid"), shape("shape.sdss"),
        nSigmaForRadius(6.0), nRadiusForFlux(2.0)
    {}

private:
    virtual PTR(AlgorithmControl) _clone() const;
    virtual PTR(Algorithm) _makeAlgorithm(
        afw::table::Schema & schema, PTR(daf::base::PropertyList) const & metadata
    ) const;
};
