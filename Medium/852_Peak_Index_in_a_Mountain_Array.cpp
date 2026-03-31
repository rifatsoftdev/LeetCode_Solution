#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Peak Index in a Mountain Array (Linear Search):
    1. Iterate through the array starting from the second element up to the second to last element.
    2. Check if the current element is greater than both its predecessor and its successor.
    3. If such an element is found, return its index as the peak.

Time Complexity: O(n)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         for (int i = 1; i < arr.size()-1; i++) {
//             if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) return i;
//         }
//         return -1;
//     }
// };




/* ================================================================================
Solution 2:

Peak Index in a Mountain Array (Binary Search):
    1. Use binary search to find the peak element in the mountain array.
    2. Compare the middle element with its next element to determine if the peak lies to the left or right.
    3. If `arr[mid] < arr[mid + 1]`, the peak must be to the right of `mid`, so update `left = mid + 1`.
    4. Otherwise, the peak is at `mid` or to its left, so update `right = mid`.
    5. The loop continues until `left` and `right` converge at the peak index.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> arr1 = {0,1,0};
    cout << solution.peakIndexInMountainArray(arr1) << endl;

    vector<int> arr2 = {0,2,1,0};
    cout << solution.peakIndexInMountainArray(arr2) << endl;

    vector<int> arr3 = {0,10,5,2};
    cout << solution.peakIndexInMountainArray(arr3) << endl;

    return 0;
}