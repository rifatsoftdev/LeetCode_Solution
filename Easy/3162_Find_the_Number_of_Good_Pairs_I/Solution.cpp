#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count = 0;

        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] % (nums2[j] * k) == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1_1 = {1, 3, 4};
    vector<int> nums2_1 = {1, 3, 4};
    int k1 = 1;
    cout << solution.numberOfPairs(nums1_1, nums2_1, k1) << endl;

    // test cases 2
    vector<int> nums1_2 = {1, 2, 4, 12};
    vector<int> nums2_2 = {2, 4};
    int k2 = 3;
    cout << solution.numberOfPairs(nums1_2, nums2_2, k2) << endl;

    return 0;
}