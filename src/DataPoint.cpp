#include "../include/DataPoint.h"

// Constructor: initialise features and label
DataPoint::DataPoint(const std::vector<double>& features, const std::string& label) {
    this->features = features;
    this->label    = label;
}

// Return features vector (by const reference — avoids unnecessary copy)
const std::vector<double>& DataPoint::getFeatures() const {
    return features;
}

// Return class label (by const reference)
const std::string& DataPoint::getLabel() const {
    return label;
}

// Return how many features this point has
int DataPoint::featureCount() const {
    return (int)features.size();
}
