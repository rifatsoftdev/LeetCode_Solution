#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Next Permutation (Optimal Lexicographical Algorithm):
    1. Find the first index `pivot` from the right such that `nums[pivot] < nums[pivot + 1]`. This is the point where the descending order is broken.
    2. If no such index exists, the array is sorted in descending order; reverse it to get the smallest permutation.
    3. If a `pivot` is found, find the smallest element to the right of `pivot` that is greater than `nums[pivot]`.
    4. Swap `nums[pivot]` with this element.
    5. Reverse the portion of the array to the right of `pivot` to make it the smallest possible lexicographical sequence.

Time Complexity: O(n) - We traverse the array at most three times.
Space Complexity: O(1) - The transformation is performed in-place.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();

        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n-1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        int i = pivot + 1;
        int j = n - 1;

        while (i <= j) {
            swap(nums[i++],nums[j--]);
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<int> nums1 = {1,2,3};
    solution.nextPermutation(nums1);
    printVec(nums1);

    vector<int> nums2 = {3,2,1};
    solution.nextPermutation(nums2);
    printVec(nums2);

    return 0;
}