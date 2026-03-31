#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/* ================================================================================
Solution 1:

Selection Sort: O(n^2)
    1. Iterate through the array from the last element to the first.
    2. For each position, find the maximum element in the unsorted portion of the array (from the start to the current position).
    3. Swap the maximum element with the element at the current position.

Time Complexity: O(n^2) due to the nested loops.
Space Complexity: O(1) as we are sorting the array in place without using any additional data structures.
*/

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         for (int i = nums.size()-1; i >= 0; i--) {
//             int max_idx = i;
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] > nums[max_idx]) {
//                     max_idx = j;
//                 }
//             }
//             swap(nums[i], nums[max_idx]);
//         }
//     }
// };




/* ================================================================================
Solution 2:

Counting Sort (Two-Pass):
    1. Count the number of occurrences of each color (0, 1, and 2) in the array.
    2. Overwrite the original array with the correct number of 0s, then 1s, and finally 2s based on the counts.

Time Complexity: O(n) as we traverse the array twice.
Space Complexity: O(1) as we only use a few variables to store the counts.
*/

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int color1 = 0, color2 = 0, color3 = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 0) color1++;
//             else if (nums[i] == 1) color2++;
//             else color3++;
//         }

//         int idx = 0;

//         for (int i = 0; i < color1; i++) {
//             nums[idx++] = 0;
//         }

//         for (int i = 0; i < color2; i++) {
//             nums[idx++] = 1;
//         }

//         for (int i = 0; i < color3; i++) {
//             nums[idx++] = 2;
//         }
//     }
// };




/* ================================================================================
Solution 3:

Dutch National Flag Algorithm (One-Pass):
    1. Use three pointers: `low`, `mid`, and `high`.
    2. `low` and `mid` start at the beginning (0), and `high` starts at the end (n-1).
    3. Iterate while `mid <= high`:
        - If `nums[mid] == 0`, swap `nums[low]` and `nums[mid]`, then increment both `low` and `mid`.
        - If `nums[mid] == 1`, just increment `mid`.
        - If `nums[mid] == 2`, swap `nums[mid]` and `nums[high]`, then decrement `high`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {2,0,2,1,1,0};
    solution.sortColors(nums1);
    printVec(nums1);

    vector<int> nums2 = {2,0,1};
    solution.sortColors(nums2);
    printVec(nums2);

    return 0;
}