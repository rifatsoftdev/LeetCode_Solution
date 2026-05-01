#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Trapping Rain Water (Dynamic Programming):
    1. Create two arrays, `leftMax` and `rightMax`, of the same size as the input array.
    2. `leftMax[i]` stores the maximum height of a bar to the left of index `i` (including itself).
    3. `rightMax[i]` stores the maximum height of a bar to the right of index `i` (including itself).
    4. For each index `i`, the amount of water trapped is determined by the minimum of `leftMax[i]` and `rightMax[i]`, minus the height of the bar at `i`.
    5. Sum the trapped water for all indices to get the total.

Time Complexity: O(n)
Space Complexity: O(n)
*/

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n == 0) return 0;

//         vector<int> leftMax(n);
//         vector<int> rightMax(n);

//         leftMax[0] = height[0];
//         for (int i = 1; i < n; i++) {
//             leftMax[i] = max(leftMax[i - 1], height[i]);
//         }

//         rightMax[n - 1] = height[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             rightMax[i] = max(rightMax[i + 1], height[i]);
//         }

//         int water = 0;
//         for (int i = 0; i < n; i++) {
//             water += min(leftMax[i], rightMax[i]) - height[i];
//         }

//         return water;
//     }
// };




/* ================================================================================
Solution 2:

Trapping Rain Water (Prefix/Suffix Max approach):
    1. Find the maximum height in the array and its index to act as a peak.
    2. Traverse from the left side to the peak, maintaining the maximum height seen so far (`maxLeft`). If the current height is less than `maxLeft`, the difference is the water trapped.
    3. Traverse from the right side to the peak, maintaining the maximum height seen so far (`maxRight`). If the current height is less than `maxRight`, the difference is the water trapped.
    4. The total water trapped is the sum of water calculated from both sides.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxLeft = 0, maxRight = 0;
        int maxHeight = height[0], idx = 0;
        int water = 0;

        // max height
        for (int i = 1; i < n; i++) {
            if (height[i] > maxHeight) {
                maxHeight = height[i];
                idx = i;
            }
        }

        // left
        for (int i = 0; i < idx; i++) {
            if (maxLeft > height[i]) {
                water += maxLeft - height[i];
            } else {
                maxLeft = height[i];
            }
        }

        // right
        for (int i = n-1; i > idx; i--) {
            if (maxRight > height[i]) {
                water += maxRight - height[i];
            } else {
                maxRight = height[i];
            }
        }

        return water;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << solution.trap(height1) << endl;
    
    vector<int> height2 = {4,2,0,3,2,5};
    cout << solution.trap(height2) << endl;

    return 0;
}