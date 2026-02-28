#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Recursion):
1. Use recursion to calculate the Fibonacci number.

Time Complexity: O(2^n)
Space Complexity: O(n) (due to the call stack)
*/

class Solution {
public:
    int fib(int n) {
        // base case
        if (n <= 1) return n;

        return fib(n-1) + fib(n-2);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout << solution.fib(2) << endl;
    cout << solution.fib(3) << endl;
    cout << solution.fib(4) << endl;

    return 0;
}