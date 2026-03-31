#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Sliding Window Maximum (Brute Force):
    1. Iterate through each possible sliding window of size `k` in the array.
    2. For each window, find the maximum element by iterating through all `k` elements.
    3. Store the maximum of each window in a result vector.

Time Complexity: O(n * k)
Space Complexity: O(1) (excluding the output vector)

Note: This approach will result in a Time Limit Exceeded (TLE) error for large inputs.
*/

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;

//         for (int i = 0; i < n-k+1; i++) {
//             int max = nums[i];

//             for (int j = i+1; j < i+k; j++) {
//                 if (nums[j] > max) max = nums[j];
//             }

//             ans.push_back(max);
//         }

//         return ans;
//     }
// };




/* ================================================================================
Solution 2:

Optimal Solution (Deque):
    1. Use a deque to store indices of elements in the current window.
    2. Maintain the deque such that the elements at the indices are in descending order.
    3. For each new element at index `i`:
        - Remove indices from the front that are out of the window's range (i.e., `index <= i - k`).
        - Remove indices from the back where the corresponding element is smaller than the current element `nums[i]`.
        - Push the current index `i` to the back of the deque.
    4. The element at the front of the deque is the maximum for the current window.
    5. Add the maximum to the result vector once the first window of size `k` is processed.

Time Complexity: O(n) - Each element is pushed and popped from the deque at most once.
Space Complexity: O(k) - The deque stores at most `k` indices.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> nums1 = {1,3,-1,-3,5,3,6,7};
    vector<int> ans1 = solution.maxSlidingWindow(nums1, 3);
    printVec(ans1);

    vector<int> nums2 = {1};
    vector<int> ans2 = solution.maxSlidingWindow(nums2, 1);
    printVec(ans2);

    return 0;
}