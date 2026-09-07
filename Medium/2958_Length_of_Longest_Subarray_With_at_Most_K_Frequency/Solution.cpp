#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> nums1 = {1,2,3,1,2,3,1,2};
    int k1 = 2;
    cout << solution.maxSubarrayLength(nums1, k1) << endl;  // Output: 6

    // test cases 2
    vector<int> nums2 = {1,2,1,2,1,2,1,2};
    int k2 = 1;
    cout << solution.maxSubarrayLength(nums2, k2) << endl;  // Output: 2

    // test cases 3
    vector<int> nums3 = {5,5,5,5,5,5,5};
    int k3 = 4;
    cout << solution.maxSubarrayLength(nums3, k3) << endl;  // Output: 4

    return 0;
}