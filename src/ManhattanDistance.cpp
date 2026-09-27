#include "../include/ManhattanDistance.h"
#include <cmath>

// Manhattan distance: sum of absolute differences per feature.
// Formula: sum of |ai - bi| for each feature i
double ManhattanDistance::calculate(const DataPoint& a, const DataPoint& b) {
    const std::vector<double>& fa = a.getFeatures();
    const std::vector<double>& fb = b.getFeatures();

    double sum = 0.0;

    for (int i = 0; i < (int)fa.size(); i++) {
        sum += std::fabs(fa[i] - fb[i]);
    }

    return sum;
}
