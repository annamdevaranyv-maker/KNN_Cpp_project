#ifndef MANHATTANDISTANCE_H
#define MANHATTANDISTANCE_H

#include "IDistance.h"

// Derived class: computes Manhattan (city-block) distance.
// Inherits from IDistance and overrides calculate().
class ManhattanDistance : public IDistance {
public:
    // |x1-y1| + |x2-y2| + |x3-y3| + |x4-y4|
    double calculate(const DataPoint& a, const DataPoint& b) override;
};

#endif // MANHATTANDISTANCE_H
