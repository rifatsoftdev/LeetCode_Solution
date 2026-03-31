#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Next Greater Element II:
    1. You are given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]).
    2. For each element in nums, find the next greater element. The next greater element of a number x is the first greater number to its traversing-order next in nums, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        st.push(arr[n-1]);

        for (int i = n-2; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }

        return ans;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }

        vector<int> ans = nextGreater(nums);

        for (int i = 0; i < n; i++) {
            ans.pop_back();
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums = {1, 2, 1};
    vector<int> ans = solution.nextGreaterElements(nums);
    printVec(ans);

    return 0;
}