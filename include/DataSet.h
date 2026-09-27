#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <string>
#include "DataPoint.h"

// Holds the full collection of labelled DataPoints.
// Demonstrates composition: DataSet "has a" vector of DataPoints.
class DataSet {
private:
    std::vector<DataPoint> points;  // All loaded data points

public:
    DataSet();  // Default constructor

    // Add a single DataPoint to the collection
    void addPoint(const DataPoint& point);

    // Load data points from a CSV file (format: f1,f2,f3,f4,label)
    bool loadCSV(const std::string& filepath);

    // Access the full list of points (read-only)
    const std::vector<DataPoint>& getPoints() const;

    // Number of points currently loaded
    int size() const;
};

#endif // DATASET_H
