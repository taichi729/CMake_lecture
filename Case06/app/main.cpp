#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

int main() {
    int size = 1000000000;
    std::vector<double> vec(size, 1.0);

    // Without OpenMP
    auto start = std::chrono::high_resolution_clock::now();
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vec[i];
        }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Without OpenMP: " << sum << " Time: " << duration << " microseconds\n";

    // With OpenMP
    start = std::chrono::high_resolution_clock::now();
    sum = 0;
#pragma omp parallel for
    for (int i = 0; i < size; i++) {
        sum += vec[i];
        }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "With OpenMP: " << sum << " Time: " << duration << " microseconds\n";

    return 0;
    }
