#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;



// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Clumsy Factorial (Stack-based Simulation):
    1. Use a stack to handle the precedence of operations: multiplication (*) and division (/) have higher precedence than addition (+) and subtraction (-).
    2. Start with the first number `n` on the stack and iterate downwards.
    3. Use a counter or state variable to cycle through the operations in the order: *, /, +, -.
    4. For multiplication and division, pop the top element, perform the operation with the current number, and push the result back.
    5. For addition, push the current number onto the stack.
    6. For subtraction, push the negative of the current number onto the stack.
    7. Finally, sum all the elements in the stack to get the result.

Time Complexity: O(n)
Space Complexity: O(n)
*/

// class Solution {
// public:
//     int clumsy(int n) {
//         stack<int> st;
//         st.push(n);
//         n--;

//         int op = 0; // 0=*, 1=/, 2=+, 3=-

//         while (n > 0) {

//             if (op == 0) { // *
//                 int top = st.top();
//                 st.pop();
//                 st.push(top * n);
//             }

//             else if (op == 1) { // /
//                 int top = st.top();
//                 st.pop();
//                 st.push(top / n);
//             }

//             else if (op == 2) { // +
//                 st.push(n);
//             }

//             else { // -
//                 st.push(-n);
//             }

//             op = (op + 1) % 4;
//             n--;
//         }

//         int ans = 0;

//         while (!st.empty()) {
//             ans += st.top();
//             st.pop();
//         }

//         return ans;
//     }
// };


/* ================================================================================
Solution 2:

Clumsy Factorial (Mathematical Pattern):
    1. For small values of n (1 to 4), the results are: 1->1, 2->2, 3->6, 4->7.
    2. For n > 4, a repeating pattern emerges based on n % 4:
        - If n % 4 == 1 or 2, the result is n + 2.
        - If n % 4 == 3, the result is n - 1.
        - If n % 4 == 0, the result is n + 1.
    3. This pattern allows for an O(1) time complexity solution.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int clumsy(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;
        if (n == 4) return 7;

        if (n % 4 == 0) return n + 1;
        if (n % 4 == 1) return n + 2;
        if (n % 4 == 2) return n + 2;
        return n - 1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.clumsy(4) << endl; // Output: 7
    cout << solution.clumsy(10) << endl; // Output: 12

    return 0;
}