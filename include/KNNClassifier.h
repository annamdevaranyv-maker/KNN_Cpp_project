#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H

#include <string>
#include "DataSet.h"
#include "IDistance.h"

// KNN classifier.
// Demonstrates composition: KNNClassifier "has a" IDistance (pointer).
// Uses polymorphism: works with any IDistance implementation.
class KNNClassifier {
private:
    int k;                    // Number of nearest neighbours to consider
    IDistance* distanceMetric; // Pointer to the chosen distance strategy

public:
    // Constructor: takes k and a pointer to any IDistance object
    KNNClassifier(int k, IDistance* distanceMetric);

    // Predict the class label of a new (unlabelled) DataPoint
    // using the provided training DataSet
    std::string predict(const DataPoint& newPoint, const DataSet& trainingData);
};

#endif // KNNCLASSIFIER_H
