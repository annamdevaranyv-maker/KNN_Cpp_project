# MiniKNN – A Beginner KNN Classifier in C++

## What is KNN?

K-Nearest Neighbours (KNN) is a simple classification algorithm.
Given a new, unlabelled data point, it:
1. Calculates the distance from that point to every known, labelled point.
2. Selects the **K** closest points (the neighbours).
3. Counts which class appears most often among those K neighbours.
4. Returns that class as the predicted label.

KNN does not build an explicit model — it simply remembers all training examples and uses them at prediction time.

---

## What is MiniKNN?

MiniKNN is a small C++ implementation of KNN for the Iris dataset.
It is a college OOP project that demonstrates:

- Classes and objects
- Encapsulation (private data, public interface)
- Composition (a class "has a" member of another class)
- Inheritance (derived classes extend a base class)
- Abstract classes and pure virtual functions
- Polymorphism (one interface, multiple implementations)

---

## Project Structure

```
MiniKNN/
├── include/          <- Header files (class declarations)
├── src/              <- Source files (class implementations)
├── data/             <- iris.csv (150-row Iris dataset)
├── main.cpp          <- Entry point
├── Makefile          <- Build instructions
└── README.md         <- This file
```

---

## Class Roles

### DataPoint
Represents one row of the Iris dataset.
- **Private**: `features` (4 doubles), `label` (string)
- **Public**: constructor, `getFeatures()`, `getLabel()`, `featureCount()`

### DataSet
Holds a collection of DataPoints.  
Demonstrates **composition**: DataSet *has a* `vector<DataPoint>`.
- `loadCSV(filepath)` — reads the Iris CSV file line by line
- `addPoint(point)` — adds one DataPoint
- `getPoints()` — returns all points
- `size()` — returns the number of loaded points

### IDistance *(abstract base class)*
Defines the interface for any distance metric.
Contains one **pure virtual** function:
```cpp
virtual double calculate(const DataPoint& a, const DataPoint& b) = 0;
```
Any class that inherits from IDistance must implement `calculate()`.

### EuclideanDistance
Derived from `IDistance`.  
Computes straight-line distance:
```
sqrt( (x1-y1)^2 + (x2-y2)^2 + (x3-y3)^2 + (x4-y4)^2 )
```

### ManhattanDistance
Derived from `IDistance`.  
Computes city-block distance:
```
|x1-y1| + |x2-y2| + |x3-y3| + |x4-y4|
```

### KNNClassifier
The main classifier.  
Demonstrates **composition**: KNNClassifier *has a* pointer to `IDistance`.  
- `predict(newPoint, trainingData)` — returns the predicted class label

---

## How to Compile

Make sure `g++` is installed.

**Using the Makefile:**
```bash
make
```

**Or compile manually:**
```bash
g++ -Wall -std=c++11 -I. main.cpp src/DataPoint.cpp src/DataSet.cpp src/EuclideanDistance.cpp src/ManhattanDistance.cpp src/KNNClassifier.cpp -o MiniKNN
```

---

## How to Run

```bash
./MiniKNN
```
*(On Windows: `MiniKNN.exe`)*

---

## Example Session

```
================================
        MiniKNN Classifier
================================

Loading data/iris.csv...
150 data points loaded.

Enter K (number of neighbours): 5

Choose distance metric:
  1. Euclidean
  2. Manhattan
Enter choice: 1
Using Euclidean distance.

Enter the new Iris point to classify:
  Sepal Length: 5.0
  Sepal Width : 3.4
  Petal Length: 1.5
  Petal Width : 0.2

================================
Predicted class: Iris-setosa
================================
```

---

## Iris Dataset

- 150 rows total: 50 per class
- 3 classes: `Iris-setosa`, `Iris-versicolor`, `Iris-virginica`
- 4 features: Sepal Length, Sepal Width, Petal Length, Petal Width
