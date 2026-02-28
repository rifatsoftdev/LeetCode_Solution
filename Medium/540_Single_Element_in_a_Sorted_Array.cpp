#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Linear Search):
1. Iterate through the array and count the occurrences of each element.
2. Return the element that occurs only once.

Time Complexity: O(n)
Space Complexity: O(n)
*/

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         for (size_t i = 0; i < nums.size(); ++i) {
//             if ((i == 0 || nums[i] != nums[i - 1]) && (i == nums.size() - 1 || nums[i] != nums[i + 1])) {
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };


/*
Optimal Approach (Binary Search):
1. Use binary search to find the single element in the sorted array.
2. Check the middle element and its neighbors to determine which half of the array contains the single element.
3. Continue the search in the appropriate half until the single element is found.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] == nums[mid + 1]) {
                start = mid + 2;
            } else {
                end = mid;
            }
        }
        
        return nums[start];
    }
};



int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    cout << solution.singleNonDuplicate(nums1) << endl; // Output: 2

    vector<int> nums2 = {3,3,7,7,10,11,11};
    cout << solution.singleNonDuplicate(nums2) << endl; // Output: 10

    return 0;
}