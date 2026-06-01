#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0;
        int count = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxNum = max(maxNum, count);
            } else {
                count = 0;
            }
        }

        return maxNum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,1,0,1,1,1};
    cout << solution.findMaxConsecutiveOnes(nums1) << endl;
    
    // test cases 2
    vector<int> nums2 = {1,0,1,1,0,1};
    cout << solution.findMaxConsecutiveOnes(nums2) << endl;

    return 0;
}