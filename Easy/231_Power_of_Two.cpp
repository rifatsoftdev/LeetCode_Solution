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
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int f = 0;
        
        while (n > 0) {
            char binary = (n % 2 == 0 ? '0' : '1');
            if (binary == '1') f++;
            n /= 2;
            if (f > 1) return false;
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.isPowerOfTwo(1) << endl;
    cout << solution.isPowerOfTwo(16) << endl;
    cout << solution.isPowerOfTwo(3) << endl;

    return 0;
}