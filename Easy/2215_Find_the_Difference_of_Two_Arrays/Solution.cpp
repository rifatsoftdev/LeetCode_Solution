#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> ans1, ans2;

        for (int num : set1) {
            if (!set2.count(num)) {
                ans1.push_back(num);
            }
        }

        for (int num : set2) {
            if (!set1.count(num)) {
                ans2.push_back(num);
            }
        }

        return {ans1, ans2};
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> result = solution.findDifference(nums1, nums2);
    printVec2D(result);

    // test cases 2
    vector<int> nums3 = {1, 2, 3, 3};
    vector<int> nums4 = {1, 1, 2, 2};
    result = solution.findDifference(nums3, nums4);
    printVec2D(result);

    return 0;
}