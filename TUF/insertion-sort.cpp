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
void insertionSort(std::vector<int> &vec) {
    for(int i=1; i < vec.size(); i++) {
        int key = vec[i];
        int j=i-1;
        while(j >=0 && vec[j]>key) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}

int main() {
    // Optimizing I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> vec =  {5, 4, 3, 2, 1};

    insertionSort(vec);

    for(int i : vec ) {
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