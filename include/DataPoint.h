#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <vector>
#include <string>

// Represents one row in the Iris dataset.
// Each point has 4 numerical features and one string label.
class DataPoint {
private:
    std::vector<double> features;  // e.g. {5.1, 3.5, 1.4, 0.2}
    std::string label;             // e.g. "Iris-setosa"

public:
    // Constructor: accepts the 4 feature values and the class label
    DataPoint(const std::vector<double>& features, const std::string& label);

    // Getters
    const std::vector<double>& getFeatures() const;
    const std::string& getLabel() const;

    // Returns the number of features (should be 4 for Iris)
    int featureCount() const;
};

#endif // DATAPOINT_H
