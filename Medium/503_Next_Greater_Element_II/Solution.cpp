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



/* ================================================================================
Solution 2:

Next Greater Element II:
    1. We can use a stack to keep track of the indices of the elements in the array.
    2. We iterate through the array twice (to handle the circular nature), and for each element, we pop from the stack until we find an element that is greater than the current element.
    3. For each popped index, we set the corresponding position in the answer array to the current element.
    4. If we are in the first pass (i < n), we push the current index onto the stack.

Time Complexity: O(n) - Each element is pushed and popped from the stack at most once.
Space Complexity: O(n) - In the worst case, the stack can hold all the indices in the array.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];

            while (!st.empty() && nums[st.top()] < num) {
                ans[st.top()] = num;
                st.pop();
            }

            if (i < n) {
                st.push(i);
            }
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