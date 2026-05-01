#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Daily Temperatures (Brute Force):
    1. For each day, iterate through the remaining days in the array to find the first day with a higher temperature.
    2. If a warmer day is found, calculate the difference in indices and store it in the result.
    3. If no warmer day is found after checking all subsequent days, store 0.

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding the output vector)

Note: This approach is simple but may result in a Time Limit Exceeded (TLE) for large input sizes.
*/

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> ans;

//         for (int i = 0; i < temperatures.size(); i++) {
//             bool flag = 0;

//             for (int j = i+1; j < temperatures.size(); j++) {
//                 if (temperatures[i] < temperatures[j]) {
//                     ans.push_back((j-i));
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (!flag) {
//                 ans.push_back(0);
//             }
//         }

//         return ans;
//     }
// };




/* ================================================================================
Solution 2:

Optimal Solution (Monotonic Stack):
    1. Use a stack to keep track of the indices of the temperatures.
    2. Iterate through the temperatures array. For each temperature, while the stack is not empty and the current temperature is greater than the temperature at the index stored at the top of the stack:
        - Pop the index from the stack.
        - Calculate the difference between the current index and the popped index.
        - Store this difference in the result array at the popped index.
    3. Push the current index onto the stack.
    4. This ensures that each index is pushed and popped at most once.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> temperatures1 = {73,74,75,71,69,72,76,73};
    vector<int> ans1 = solution.dailyTemperatures(temperatures1);
    printVec(ans1);

    vector<int> temperatures2 = {30,40,50,60};
    vector<int> ans2 = solution.dailyTemperatures(temperatures2);
    printVec(ans2);

    vector<int> temperatures3 = {30,60,90};
    vector<int> ans3 = solution.dailyTemperatures(temperatures3);
    printVec(ans3);

    return 0;
}