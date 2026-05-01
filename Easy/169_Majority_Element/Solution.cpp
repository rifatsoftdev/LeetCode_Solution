#include <iostream>
#include <vector>
#include <algorithm>
#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int, int> mp;
//         int n = nums.size();
//         int majority = 0;
//         int max = 0;

//         if (n % 2 == 0) majority = (nums.size() / 2);
//         else majority = (nums.size() / 2) + 1;

//         for (int i = 0; i < n; i++) {
//             mp[nums[i]]++;

//             if (mp[nums[i]] >= majority) {
//                 max = nums[i];
//             }
//         }

//         return max;
//     }
// };


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {3,2,3};
    cout << solution.majorityElement(nums1) << endl;

    vector<int> nums2 = {2,2,1,1,1,2,2};
    cout << solution.majorityElement(nums2) << endl;

    return 0;
}