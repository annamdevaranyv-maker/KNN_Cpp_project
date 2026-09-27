# ============================================================
# Makefile for MiniKNN
# Usage:
#   make          -> build the program (produces MiniKNN.exe on Windows)
#   make clean    -> remove compiled files
# ============================================================

CXX     = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Source files
SRCS = main.cpp \
       src/DataPoint.cpp \
       src/DataSet.cpp \
       src/EuclideanDistance.cpp \
       src/ManhattanDistance.cpp \
       src/KNNClassifier.cpp

# Output executable name
TARGET = MiniKNN

# Default target: compile everything
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Remove compiled output
clean:
	del $(TARGET).exe 2>nul || rm -f $(TARGET)
