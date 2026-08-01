#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 1;

        for (int num : nums) {
            if (num == target) {
                target++;
            } else if (num > target) {
                break;
            }
        }

        return target;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,2,0};
    cout << solution.firstMissingPositive(nums1) << endl;
    
    // test cases 2
    vector<int> nums2 = {3,4,-1,1};
    cout << solution.firstMissingPositive(nums2) << endl;

    // test cases 3
    vector<int> nums3 = {7,8,9,11,12};
    cout << solution.firstMissingPositive(nums3) << endl;

    return 0;
}