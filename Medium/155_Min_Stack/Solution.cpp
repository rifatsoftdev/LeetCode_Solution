#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Min Stack:
    1. Use two stacks: one for the actual values, and another for the minimum values.
    2. When pushing a value, compare it with the current minimum (top of the min stack). If the new value is smaller than or equal to the current minimum, also push it onto the min stack.
    3. When popping a value, if the popped value is the same as the current minimum, pop it from the min stack as well.
    4. The top of the min stack always holds the current minimum value, which can be returned in O(1) time.

Time Complexity: O(1) for push, pop, top, and getMin operations.
Space Complexity: O(n) in the worst case, where n is the number of elements in the stack (if all elements are the same and are the minimum).
*/

class MinStack {
public:
    stack<int> s;
    stack<int> min_s;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (min_s.empty() || val <= min_s.top()) {
            min_s.push(val);
        }
    }
    
    void pop() {
        if (!s.empty()) {
            if (s.top() == min_s.top()) {
                min_s.pop();
            }
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
*/


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MinStack* obj = new MinStack();

    return 0;
}