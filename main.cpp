#include <iostream>
#include <vector>

#include "include/DataSet.h"
#include "include/KNNClassifier.h"
#include "include/EuclideanDistance.h"
#include "include/ManhattanDistance.h"
#include "include/IDistance.h"

int main() {
    std::cout << "================================" << std::endl;
    std::cout << "        MiniKNN Classifier      " << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << std::endl;

    // --- Load the Iris dataset ---
    DataSet dataset;
    std::cout << "Loading data/iris.csv..." << std::endl;

    if (!dataset.loadCSV("data/iris.csv")) {
        std::cerr << "Failed to load iris.csv. Make sure it is in the data/ folder." << std::endl;
        return 1;
    }

    std::cout << dataset.size() << " data points loaded." << std::endl;
    std::cout << std::endl;

    // --- Get K from user ---
    int k = 0;
    std::cout << "Enter K (number of neighbours): ";
    std::cin >> k;

    if (k <= 0 || k > dataset.size()) {
        std::cerr << "Invalid K value. Must be between 1 and " << dataset.size() << "." << std::endl;
        return 1;
    }

    // --- Choose distance metric ---
    std::cout << std::endl;
    std::cout << "Choose distance metric:" << std::endl;
    std::cout << "  1. Euclidean" << std::endl;
    std::cout << "  2. Manhattan" << std::endl;
    std::cout << "Enter choice: ";

    int choice = 0;
    std::cin >> choice;

    // Declare pointers for polymorphism demonstration
    EuclideanDistance euclidean;
    ManhattanDistance manhattan;
    IDistance* distMetric = nullptr;

    switch (choice) {
        case 1:
            distMetric = &euclidean;
            std::cout << "Using Euclidean distance." << std::endl;
            break;
        case 2:
            distMetric = &manhattan;
            std::cout << "Using Manhattan distance." << std::endl;
            break;
        default:
            std::cerr << "Invalid choice. Please enter 1 or 2." << std::endl;
            return 1;
    }

    // --- Build the classifier ---
    KNNClassifier classifier(k, distMetric);

    // --- Get a new data point from the user ---
    std::cout << std::endl;
    std::cout << "Enter the new Iris point to classify:" << std::endl;

    double sepalLength, sepalWidth, petalLength, petalWidth;

    std::cout << "  Sepal Length: ";
    std::cin >> sepalLength;

    std::cout << "  Sepal Width : ";
    std::cin >> sepalWidth;

    std::cout << "  Petal Length: ";
    std::cin >> petalLength;

    std::cout << "  Petal Width : ";
    std::cin >> petalWidth;

    // Build the new DataPoint (label is empty because it is unlabelled)
    std::vector<double> newFeatures;
    newFeatures.push_back(sepalLength);
    newFeatures.push_back(sepalWidth);
    newFeatures.push_back(petalLength);
    newFeatures.push_back(petalWidth);

    DataPoint newPoint(newFeatures, "");

    // --- Predict ---
    std::string predicted = classifier.predict(newPoint, dataset);

    std::cout << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << "Predicted class: " << predicted  << std::endl;
    std::cout << "================================" << std::endl;

    return 0;
}
