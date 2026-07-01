#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int sum = 0;

        for (int i = 0; i < 32; i++){
            int c = 0;

            for (int val : nums) {
                if (val & (1 << i)) c++;
            }

            if (c >= k) sum += pow(2, i);
        }

        return sum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {7, 12, 9, 8, 9, 15};
    int k1 = 4;
    cout << solution.findKOr(nums1, k1) << endl;
    
    // test cases 2
    vector<int> nums2 = {2, 12, 1, 11, 4, 5};
    int k2 = 6;
    cout << solution.findKOr(nums2, k2) << endl;

    // test cases 3
    vector<int> nums3 = {10, 8, 5, 9, 11, 6, 8};
    int k3 = 1;
    cout << solution.findKOr(nums3, k3) << endl;

    return 0;
}