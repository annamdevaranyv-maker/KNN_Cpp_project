#include "../include/EuclideanDistance.h"
#include <cmath>

// Euclidean distance: straight-line distance in feature space.
// Formula: sqrt( sum of (ai - bi)^2 for each feature i )
double EuclideanDistance::calculate(const DataPoint& a, const DataPoint& b) {
    const std::vector<double>& fa = a.getFeatures();
    const std::vector<double>& fb = b.getFeatures();

    double sum = 0.0;

    for (int i = 0; i < (int)fa.size(); i++) {
        double diff = fa[i] - fb[i];
        sum += diff * diff;
    }

    return std::sqrt(sum);
}
