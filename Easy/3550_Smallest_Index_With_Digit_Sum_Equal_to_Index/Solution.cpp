#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    int sumFoDigit(int n) {
        int ans = 0;

        while (n != 0) {
            int d = n % 10;
            ans += d;
            n /= 10;
        }

        return ans;
    }

public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i == sumFoDigit(nums[i])) {
                return i;
            }
        }

        return -1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,3,2};
    cout << solution.smallestIndex(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {1,10,11};
    cout << solution.smallestIndex(nums2) << endl;

    // test cases 3
    vector<int> nums3 = {1,2,3};
    cout << solution.smallestIndex(nums3) << endl;

    return 0;
}