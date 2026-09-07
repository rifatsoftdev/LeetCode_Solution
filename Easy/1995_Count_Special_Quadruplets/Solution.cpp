#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                for (int c = b + 1; c < n; c++) {
                    for (int d = c + 1; d < n; d++) {
                        if (nums[a] + nums[b] + nums[c] == nums[d]) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,2,3,6};
    cout << solution.countQuadruplets(nums1) << endl; // Output: 1

    // test cases 2
    vector<int> nums2 = {3,3,6,4,5};
    cout << solution.countQuadruplets(nums2) << endl; // Output: 0

    // test cases 3
    vector<int> nums3 = {1,1,1,3,5};
    cout << solution.countQuadruplets(nums3) << endl; // Output: 4

    return 0;
}