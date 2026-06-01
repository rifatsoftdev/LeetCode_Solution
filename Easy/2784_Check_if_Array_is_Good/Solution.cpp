#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    int maxNum(vector<int>& nums) {
        int m = 0;
        for (int i : nums)  m = max(m, i);
        return m;
    }

public:
    bool isGood(vector<int>& nums) {
        int maxVal = maxNum(nums);

        if (nums.size() != maxVal + 1) return false;

        vector<int> expected;

        for (int i = 1; i < maxVal + 1; i++) expected.push_back(i);
        expected.push_back(maxVal);

        sort(nums.begin(), nums.end());

        return nums == expected;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {2, 1, 3};
    cout << solution.isGood(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {1, 3, 3, 2};
    cout << solution.isGood(nums2) << endl;

    // test cases 3
    vector<int> nums3 = {1, 1};
    cout << solution.isGood(nums3) << endl;

    // test cases 4
    vector<int> nums4 = {3, 4, 4, 1, 2, 1};
    cout << solution.isGood(nums4) << endl;

    return 0;
}