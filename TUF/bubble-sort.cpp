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


void bubbleSort(int* arr, int length) {
    for (int i=0; i < length - 1; i++) {
        for (int j=0; j < length - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    // Optimizing I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    auto start = std::chrono::high_resolution_clock::now();

    int arr[] = {5, 4, 3, 2, 1};
    int length = sizeof(arr)/sizeof(arr[0]);


    bubbleSort(arr, length);
    
    for(int i : arr) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cerr << std::fixed << std::setprecision(6) << "\n----------------------------" << std::endl;
    std::cerr << "Execution time: " << duration.count() << " seconds" << std::endl;
    std::cerr << "----------------------------" << std::endl;

    return 0;
}