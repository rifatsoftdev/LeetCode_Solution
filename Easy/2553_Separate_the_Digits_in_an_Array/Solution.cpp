#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    vector<int> num_digit(int num) {
        vector<int> ans;

        while (num != 0) {
            int digit = num % 10;
            ans.push_back(digit);
            num /= 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> tmp = num_digit(nums[i]);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {13,25,83,77};
    vector<int> ans1 = solution.separateDigits(nums1);
    printVec(ans1);

    // test cases 2
    vector<int> nums2 = {7,1,3,9};
    vector<int> ans2 = solution.separateDigits(nums2);
    printVec(ans2);

    return 0;
}