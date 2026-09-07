#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> feq;

        for (int n: nums) {
            feq[n]++;
        }

        for (const auto& [key, val] : feq) {
            if (val % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {3,2,3,2,2,2};
    cout << solution.divideArray(nums1) << endl;

    // test cases 2
    vector<int> nums2 = {1,2,3,4};
    cout << solution.divideArray(nums2) << endl;

    return 0;
}