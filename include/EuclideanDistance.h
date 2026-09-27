#ifndef EUCLIDEANDISTANCE_H
#define EUCLIDEANDISTANCE_H

#include "IDistance.h"

// Derived class: computes Euclidean (straight-line) distance.
// Inherits from IDistance and overrides calculate().
class EuclideanDistance : public IDistance {
public:
    // sqrt( (x1-y1)^2 + (x2-y2)^2 + (x3-y3)^2 + (x4-y4)^2 )
    double calculate(const DataPoint& a, const DataPoint& b) override;
};

#endif // EUCLIDEANDISTANCE_H
