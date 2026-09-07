#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,5,2};
    cout << solution.predictTheWinner(nums1) << endl; // Expected output: false

    // test cases 2
    vector<int> nums2 = {1,5,233,7};
    cout << solution.predictTheWinner(nums2) << endl; // Expected output: true

    return 0;
}