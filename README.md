# cpp-autonomy-math

Applied math for autonomy projects in C++

A collection of modular C++ demos for applied math, signal processing, and control systems in robotics and autonomy.  
Built by Luke Miller — PhD in flight control, translating real-time systems into modern C++.


## Repository Structure 
This repo is organized into focused modules, each with a single responsibility. All examples are standalone, readable, and ready to build.

---

Contents
/PID_control/

PID Controller

    Implements a discrete-time PID control loop

    Tracks a moving setpoint using velocity integration

    Outputs time, position, and control effort

/Signal_Processing/

Moving Average Filter

    Smooths noisy input data using a fixed-size sliding window

    Ideal for preprocessing sensor or simulation output

/Math/

Rotate Vector Around Z-Axis

    Applies 3D rotation using a standard rotation matrix
    Matrix Multiply

    Demonstrates nested vector-based matrix multiplication

/Clustering/

Cluster Points by Radius

    Groups 1D points into clusters based on proximity

    Useful for basic perception or map pre-processing

/Utilities/

Count Isolated Numbers

    Counts elements in a list with no adjacent neighbors

    Toy problem useful for iteration logic and boundary handling

(Additional examples coming soon...)


---


\##  How to Compile


You can compile any file with:

g++ path/to/file.cpp -o output -std=c++17
./output