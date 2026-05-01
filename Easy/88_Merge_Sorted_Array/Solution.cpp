#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Merge Sorted Array (Three Pointers):
    1. Since nums1 has enough space at the end, we can start merging from the back to avoid overwriting elements.
    2. Use three pointers: `i` starting at `m-1`, `j` starting at `n-1`, and `idx` starting at `m+n-1`.
    3. Compare `nums1[i]` and `nums2[j]`, place the larger one at `nums1[idx]`, and decrement the corresponding pointers.
    4. If any elements remain in `nums2` after `nums1` is exhausted, copy them over.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n-1;
        int i = m-1;
        int j = n-1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            } else {
                nums1[idx--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    int m1 = 3, n1 = 3;
    vector<int> nums11 = {1,2,3,0,0,0}, nums12 = {2,5,6};
    solution.merge(nums11, m1, nums12, n1);
    printVec(nums11);

    int m2 = 1, n2 = 0;
    vector<int> nums21 = {1}, nums22 = {};
    solution.merge(nums21, m2, nums22, n2);
    printVec(nums21);

    int m3 = 0, n3 = 1;
    vector<int> nums31 = {0}, nums32 = {1};
    solution.merge(nums31, m3, nums32, n3);
    printVec(nums31);

    return 0;
}