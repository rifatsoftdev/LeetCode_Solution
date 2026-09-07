#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {2, 3};
    cout << solution.uniformArray(nums1) << endl; // Expected output: true

    // test cases 2
    vector<int> nums2 = {4, 6};
    cout << solution.uniformArray(nums2) << endl; // Expected output: true

    return 0;
}