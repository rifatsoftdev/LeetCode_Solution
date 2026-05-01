#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Largest Rectangle in Histogram:
    1. For each bar, we can expand to the left and right until we find a bar that is shorter than the current bar.
    2. The area of the rectangle formed by the current bar is then calculated as:
       area = height of the current bar * (right index - left index + 1)
    3. We keep track of the maximum area found during this process.

Time Complexity: O(n^2) - In the worst case, we may have to expand to the left and right for each bar, leading to O(n) for each of the n bars.
Space Complexity: O(1) - We are using only a constant amount of extra space to store variables for the current bar, left and right indices, and the maximum area.

Note: This brute-force approach is not efficient for large inputs, and it may lead to time limit exceeded errors on platforms like LeetCode. A more optimal solution would involve using a stack to achieve O(n) time complexity.
*/

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = 0;

//         for (int i = 0; i < n; ++i) {
//             int height = heights[i];
//             int left = i, right = i;

//             while (left > 0 && heights[left - 1] >= height) {
//                 --left;
//             }
//             while (right < n - 1 && heights[right + 1] >= height) {
//                 ++right;
//             }

//             int area = height * (right - left + 1);
//             maxArea = max(maxArea, area);
//         }

//         return maxArea;
//     }
// };




/* ================================================================================
Solution 2:

Largest Rectangle in Histogram:
    1. We can use a stack to keep track of the indices of the bars in the histogram.
    2. We iterate through the heights of the bars, and for each bar, we pop from the stack until we find a bar that is shorter than the current bar.
    3. For each popped bar, we calculate the area of the rectangle formed by that bar as the height multiplied by the width, which is determined by the current index and the index of the new top of the stack.
    4. We keep track of the maximum area found during this process.

Time Complexity: O(n) - Each bar is pushed and popped from the stack at most once.
Space Complexity: O(n) - In the worst case, the stack can hold all the bars in the histogram.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1), right(n, -1);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }


        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            int area = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> heights1 = {2,1,5,6,2,3};
    cout << solution.largestRectangleArea(heights1) << endl;

    vector<int> heights2 = {2,4};
    cout << solution.largestRectangleArea(heights2) << endl;

    return 0;
}