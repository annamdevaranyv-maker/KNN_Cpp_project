#include "../include/KNNClassifier.h"
#include <climits>
#include <cfloat>

// Constructor: store k and the chosen distance metric
KNNClassifier::KNNClassifier(int k, IDistance* distanceMetric) {
    this->k               = k;
    this->distanceMetric  = distanceMetric;
}

// Predict the class label for a new unlabelled point.
// Steps:
//   1. Calculate distance from newPoint to every training point.
//   2. Find the K nearest points using a simple selection loop.
//   3. Count votes for each class among those K points.
//   4. Return the class with the most votes.
std::string KNNClassifier::predict(const DataPoint& newPoint, const DataSet& trainingData) {
    const std::vector<DataPoint>& allPoints = trainingData.getPoints();
    int totalPoints = (int)allPoints.size();

    // --- Step 1: compute distance from newPoint to every training point ---
    std::vector<double> distances(totalPoints);

    for (int i = 0; i < totalPoints; i++) {
        distances[i] = distanceMetric->calculate(newPoint, allPoints[i]);
    }

    // --- Step 2: find the K nearest neighbours using a simple selection loop ---
    // We use a "used" flag array so we never pick the same point twice.
    std::vector<bool> used(totalPoints, false);
    std::vector<std::string> neighbourLabels;

    for (int n = 0; n < k; n++) {
        int    bestIndex = -1;
        double bestDist  = DBL_MAX;

        for (int i = 0; i < totalPoints; i++) {
            if (!used[i] && distances[i] < bestDist) {
                bestDist  = distances[i];
                bestIndex = i;
            }
        }

        if (bestIndex != -1) {
            used[bestIndex] = true;
            neighbourLabels.push_back(allPoints[bestIndex].getLabel());
        }
    }

    // --- Step 3: majority vote across the 3 Iris classes ---
    // Simple counters — one per class. No map required.
    int countSetosa     = 0;
    int countVersicolor = 0;
    int countVirginica  = 0;

    for (int i = 0; i < (int)neighbourLabels.size(); i++) {
        if (neighbourLabels[i] == "Iris-setosa") {
            countSetosa++;
        } else if (neighbourLabels[i] == "Iris-versicolor") {
            countVersicolor++;
        } else if (neighbourLabels[i] == "Iris-virginica") {
            countVirginica++;
        }
    }

    // --- Step 4: return the class with the highest count ---
    if (countSetosa >= countVersicolor && countSetosa >= countVirginica) {
        return "Iris-setosa";
    } else if (countVersicolor >= countSetosa && countVersicolor >= countVirginica) {
        return "Iris-versicolor";
    } else {
        return "Iris-virginica";
    }
}
