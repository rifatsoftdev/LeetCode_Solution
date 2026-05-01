#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Next Greater Element I:
    1. The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
    2. You are given two distinct 0d integer arrays nums1 and nums2, where nums1 is a subset of nums2.
    3. For each 0d integer in nums1, find the next greater element of it in nums2 and return an array of the results.
    4. If there is no next greater element for an element, return -1 for this element.

Time Complexity: O(N + M), where N is the length of nums2 and M is the length of nums1.
Space Complexity: O(N), where N is the length of nums2, as we are using a stack to store the elements of nums2 and a hash map to store the next greater elements.
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

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums2Greater = nextGreater(nums2);
        unordered_map<int, int> m;

        for (size_t i = 0; i < nums2.size(); i++) m[nums2[i]] = nums2Greater[i];
        
        vector<int> result;
        for (int num : nums1) {
            result.push_back(m[num]);
        }
        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    printVec(result);

    return 0;
}