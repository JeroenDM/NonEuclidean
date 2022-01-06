#include <iostream>

#include "NonEuclidean/Vector.h"

int main() {
    std::cout << "Hello bazel\n";

    Vector3 v(0.0);
    Vector3 v2(1.0, 2.0, 3.0);
    v2.Normalize();
    std::cout << "result: " << v + v2 << "\n";
}