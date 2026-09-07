#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> count(1001, 0);
        vector<int> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                count[nums[i][j]]++;
            }
        }

        for (int i = 0; i < 1001; i++) {
            if (count[i] == n) {
                result.push_back(i);
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<vector<int>> nums1 = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    vector<int> result1 = solution.intersection(nums1);
    printVec(result1); // Output: [3, 4]

    // test cases 2
    vector<vector<int>> nums2 = {{1,2,3},{4,5,6}};
    vector<int> result2 = solution.intersection(nums2);
    printVec(result2); // Output: []

    return 0;
}