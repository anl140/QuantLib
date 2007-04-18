/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2007 Ferdinando Ametrano
 Copyright (C) 2007 Mark Joshi

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include <ql/models/marketmodels/models/pseudorootfacade.hpp>
#include <ql/math/pseudosqrt.hpp>

namespace QuantLib {

    PseudoRootFacade::PseudoRootFacade(
            const std::vector<Matrix>& covariancePseudoRoots,
            const std::vector<Rate>& rateTimes,
            const std::vector<Rate>& initialRates,
            const std::vector<Spread>& displacements)
    : numberOfFactors_(covariancePseudoRoots.front().columns()),
      numberOfRates_(covariancePseudoRoots.front().rows()),
      numberOfSteps_(covariancePseudoRoots.size()),
      initialRates_(initialRates),
      displacements_(displacements),
      evolution_(rateTimes),
      covariancePseudoRoots_(covariancePseudoRoots)
    {
        QL_REQUIRE(numberOfRates_==rateTimes.size()-1,
                   "mismatch between number of rates (" << numberOfRates_ <<
                   ") and rate times");
        QL_REQUIRE(numberOfRates_==displacements.size(),
                   "mismatch between number of rates (" << numberOfRates_ <<
                   ") and displacements (" << displacements.size() << ")");
        QL_REQUIRE(numberOfRates_<=numberOfFactors_*numberOfSteps_,
                   "number of rates (" << numberOfRates_ <<
                   ") greater than number of factors (" << numberOfFactors_
                   << ") times number of steps (" << numberOfSteps_ << ")");

        // evolutionTimes are not given for the time being
        QL_REQUIRE(numberOfRates_==covariancePseudoRoots.size(),
                   "number of rates (" << numberOfRates_ <<
                   ") must be equal to covariancePseudoRoots.size() (" <<
                   covariancePseudoRoots.size() << ")");

        for (Size k=0; k<numberOfSteps_; ++k) {
            QL_REQUIRE(covariancePseudoRoots_[k].rows()==numberOfRates_,
                       "step " << k
                       << ": pseudoRoot has wrong number of rows: "
                       << covariancePseudoRoots_[k].rows()
                       << " instead of " << numberOfRates_);
            // not really mandatory
            QL_REQUIRE(covariancePseudoRoots_[k].columns()==numberOfFactors_,
                       "step " << k
                       << ": pseudoRoot has wrong number of columns: "
                       << covariancePseudoRoots_[k].columns()
                       << " instead of " << numberOfFactors_);
        }
    }

}