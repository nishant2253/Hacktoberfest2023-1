#include <iostream>
#include <cmath>

double function(double x) {
    return x * x - 4;
}

double bisection(double a, double b, double tolerance, int maxIterations) {
    if (function(a) * function(b) >= 0) {
        std::cout << "Bisection method may not converge on the given interval." << std::endl;
        return NAN;
    }

    double midPoint;
    for (int i = 0; i < maxIterations; i++) {
        midPoint = (a + b) / 2;
        if (std::abs(function(midPoint)) < tolerance) {
            std::cout << "Converged after " << i + 1 << " iterations." << std::endl;
            return midPoint;
        }

        if (function(midPoint) * function(a) < 0) {
            b = midPoint;
        } else {
            a = midPoint;
        }
    }

    std::cout << "Bisection method did not converge within the specified iterations." << std::endl;
    return NAN;
}

int main() {
    double a = 0;
    double b = 5;
    double tolerance = 1e-6;
    int maxIterations = 100;

    double root = bisection(a, b, tolerance, maxIterations);

    if (!std::isnan(root)) {
        std::cout << "Approximate root: " << root << std::endl;
    }

    return 0;
}
