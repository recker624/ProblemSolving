#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

// ---------------------------------------------------------
// Logic Block
// ---------------------------------------------------------
void pattern(int n) {
    // print the triangle pattern for n lines (n is odd)
    for(int i=0; i < n; i++) {
        for (int j=0; j < 2*n-1; j++) {
            if(j >= ((2*n-1)/2 - i) && j <= ((2*n - 1)/2 + i)) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Optimizing I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    auto start = std::chrono::high_resolution_clock::now();

    int n = 5; // n must be odd
    pattern(n);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cerr << std::fixed << std::setprecision(6) << "\n----------------------------" << std::endl;
    std::cerr << "Execution time: " << duration.count() << " seconds" << std::endl;
    std::cerr << "----------------------------" << std::endl;

    return 0;
}