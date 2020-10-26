#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>
#include <iterator>     // std::distance
#include <list>         // std::list

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

        double output = 0.0;
        std::vector<int> temp_arr;
        temp_arr.reserve( nums1.size() + nums2.size() ); // preallocate memory
        int max_idx = std::min(nums1.size(), nums2.size());
        int n1_idx = 0;
        int n2_idx = 0;

        // prepare a new vector for merging two vector
        while(n1_idx < nums1.size() && n2_idx < nums2.size()) {
            if (nums1[n1_idx] < nums2[n2_idx]) {
                temp_arr.push_back(nums1[n1_idx]);
                n1_idx++;
                
            } else {
                temp_arr.push_back(nums2[n2_idx]);
                n2_idx++;
            }
        }
        
        
        // deal with the remaining numbers
        for(int i = n1_idx ; i < nums1.size() ; i++) {
            temp_arr.push_back(nums1[i]);
        }
        
        for(int i = n2_idx ; i < nums2.size() ; i++) {
            temp_arr.push_back(nums2[i]);
        }
        
        // the index of the medium number
        // ex: [1,10] [2,9] => [1,2,9,10] => medium: (2+9)/2 = 5.5
        // ex: [1,10] [2] => [1,2,10] => medium: 2
        double mid_index = (nums1.size() + nums2.size()) % 2 == 1 ? (int) ((nums1.size() + nums2.size()) / 2) : (nums1.size() + nums2.size()) / 2;
        if(temp_arr.size() % 2 == 1) {
            output = temp_arr[mid_index];
        } else {
            output = (double)(temp_arr[mid_index] + temp_arr[mid_index-1]) / 2.0;
        }
        
        return output;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> num1{1,3};
    std::vector<int> num2{2,5};
    printf("output:%f\n", s -> findMedianSortedArrays(num1, num2));
}