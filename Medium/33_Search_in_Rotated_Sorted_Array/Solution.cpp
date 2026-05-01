#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Search in Rotated Sorted Array (Linear Search):
    1. Iterate through the array from the beginning to the end.
    2. Compare each element with the target value.
    3. If the target is found, return its index.
    4. If the loop finishes without finding the target, return -1.

Time Complexity: O(n)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == target) return i; 
//         }

//         return -1;
//     }
// };




/* ================================================================================
Solution 2:

Search in Rotated Sorted Array (Binary Search):
    1. Use binary search to find the target in the rotated sorted array.
    2. In each step, determine which half of the array (left or right) is sorted.
    3. If the left half `[left, mid]` is sorted:
        - Check if the target lies within this range. If so, move `right = mid - 1`.
        - Otherwise, search in the right half by moving `left = mid + 1`.
    4. If the right half `[mid, right]` is sorted:
        - Check if the target lies within this range. If so, move `left = mid + 1`.
        - Otherwise, search in the left half by moving `right = mid - 1`.
    5. Repeat until the target is found or the search space is exhausted.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) return mid;

            // left part sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // right part sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {4,5,6,7,0,1,2};
    cout << solution.search(nums1, 0) << endl;

    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << solution.search(nums2, 3) << endl;

    vector<int> nums3 = {1};
    cout << solution.search(nums3, 0) << endl;

    return 0;
}