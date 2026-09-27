#include "../include/DataSet.h"
#include <fstream>
#include <sstream>
#include <iostream>

DataSet::DataSet() {
    // Nothing to initialise; vector starts empty by default
}

// Add one DataPoint to the collection
void DataSet::addPoint(const DataPoint& point) {
    points.push_back(point);
}

// Load Iris CSV file.
// Expected row format: sepalLen,sepalWid,petalLen,petalWid,className
bool DataSet::loadCSV(const std::string& filepath) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Error: could not open file: " << filepath << std::endl;
        return false;
    }

    std::string line;

    while (std::getline(file, line)) {
        // Skip blank lines (e.g. trailing newline at end of file)
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string token;
        std::vector<double> features;
        std::string label;

        // Read the 4 numerical feature columns
        for (int i = 0; i < 4; i++) {
            if (!std::getline(ss, token, ',')) {
                break;
            }
            features.push_back(std::stod(token));
        }

        // Read the class label (last column)
        if (std::getline(ss, token, ',')) {
            label = token;
        }

        // Only add the point if it has exactly 4 features and a label
        if (features.size() == 4 && !label.empty()) {
            DataPoint dp(features, label);
            addPoint(dp);
        }
    }

    file.close();
    return true;
}

// Return all points (read-only)
const std::vector<DataPoint>& DataSet::getPoints() const {
    return points;
}

// Return number of loaded points
int DataSet::size() const {
    return (int)points.size();
}
