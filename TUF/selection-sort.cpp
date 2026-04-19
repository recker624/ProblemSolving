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
#include<array>

void selectionSort(std::array<int, 5>& arr) {
    int length = arr.size();

    for (int i=0; i < length - 1; i++) {
        int minId = i;
        for(int j=i+1; j < length; j++) {
            if(arr[minId] > arr[j]) {
                minId = j;
            }
        }
        if (minId != i) {
            // exchange the values efficiently using XOR operator.
            arr[i] = arr[i] ^ arr[minId];
            arr[minId] = arr[i] ^ arr[minId];
            arr[i] = arr[i] ^ arr[minId];
        }

    }
}

int main() {
    // Optimizing I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    auto start = std::chrono::high_resolution_clock::now();

    std::array<int, 5> arr = {5, 4, 3 ,2 , 1};

    selectionSort(arr);

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