    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <chrono>
    #include <iomanip>
    #include <string>
    #include <cmath>

    std::vector<int> mergeSort(std::vector<int> &vec, int firstIndex, int lastIndex) {
        /*
            - Algorithm
            - find middle element and split array in two parts on the basis of that
            pass each of the split array recursively to the function
            - Take the returned outputs and compare both arrays element wise and combine them
            - Return the final sorted array.
            - This invariant holds true for arrays of all sizes.

        - Improvement:
            - This algorithm is inefficient in the sense that it allocated and deallocates vectors at runtime for every recursive iteration.
            - Instead we can preallocate an auxilarry array and sort the passed array inplace to avoid creating extra arrays. 
            - For this we can create an extra mergeSortDivide funtion while actual job is just to keep dividing the array until the 
            base case of a single element is reached. 
            - After that a merge function can be called which starts combining the base case arrays all the way to the top. 
        */
    

        // base case
        if(firstIndex == lastIndex) {
            return std::vector<int> {vec[firstIndex]};
        }

        int middleIndex = firstIndex + (lastIndex - firstIndex)/2;

        std::vector<int> first_arr = mergeSort(vec, firstIndex, middleIndex);
        std::vector<int> second_arr = mergeSort(vec, middleIndex+1, lastIndex);

        std::vector<int> final_arr;

        int i=0, j=0;
        // now that we have the sorted array, time to combine them
        for(; i < first_arr.size() && j < second_arr.size();) {
            if(first_arr[i] < second_arr[j]) {
                final_arr.push_back(first_arr[i++]);
            }
            else {
                final_arr.push_back(second_arr[j++]);
            }
        }

        while( i < first_arr.size()) {
            final_arr.push_back(first_arr[i++]);
        }

        while(j < second_arr.size()) {
            final_arr.push_back(second_arr[j++]);
        }

        return final_arr;
    }

    int main() {
        // Optimizing I/O performance
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        auto start = std::chrono::high_resolution_clock::now();

        std::vector<int> vec = {6, 5, 4, 3, 2, 1};

        std::vector<int> final_arr = mergeSort(vec, 0, vec.size() - 1);

        for(int i : final_arr) {
            std::cout << i << " ";
        }

        std::cout << std::endl;

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        std::cerr << std::fixed << std::setprecision(6) << "\n----------------------------" << std::endl;
        std::cerr << "Execution time: " << duration.count() << " seconds" << std::endl;
        std::cerr << "----------------------------" << std::endl;

        return 0;
    }