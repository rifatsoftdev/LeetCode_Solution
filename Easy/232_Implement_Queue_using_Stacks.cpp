#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*

*/

class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
        
    }
    
    void push(int x) {
        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
        input.push(x);

        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
    
    int pop() {
        int top = output.top();
        output.pop();
        return top;
    }
    
    int peek() {
        return output.top();
    }
    
    bool empty() {
        return output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
*/


class Solution {
public:
    
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}