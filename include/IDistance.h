#ifndef IDISTANCE_H
#define IDISTANCE_H

#include "DataPoint.h"

// Abstract base class for distance metrics.
// Any concrete distance class must override calculate().
// This is the interface that KNNClassifier depends on (polymorphism).
class IDistance {
public:
    // Pure virtual: every derived class must provide its own implementation
    virtual double calculate(const DataPoint& a, const DataPoint& b) = 0;

    // Virtual destructor — good practice when using inheritance
    virtual ~IDistance() {}
};

#endif // IDISTANCE_H
