#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach (Linear Search):
1. Iterate through the array and count the occurrences of each element.
2. Return the element that occurs only once.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        while (n % 4 == 0) {
            n /= 4;
        }

        return n == 1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.isPowerOfFour(16) << endl;
    cout << solution.isPowerOfFour(5) << endl;
    cout << solution.isPowerOfFour(1) << endl;

    return 0;
}