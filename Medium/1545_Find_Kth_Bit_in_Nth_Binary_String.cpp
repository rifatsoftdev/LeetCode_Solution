#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Find Kth Bit in Nth Binary String (Recursive):
    1. The sequence $S_n$ is defined as $S_n = S_{n-1} + "1" + reverse(invert(S_{n-1}))$.
    2. The length of $S_n$ is $2^n - 1$. The middle bit is always at position $mid = (2^n - 1) / 2 + 1 = 2^{n-1}$.
    3. If $k$ is the middle bit, it is always '1' (for $n > 1$).
    4. If $k < mid$, the bit is the same as the $k$-th bit in $S_{n-1}$.
    5. If $k > mid$, the bit is the inverted $(len - k + 1)$-th bit of $S_{n-1}$ due to the reverse and invert operations.
    6. Base case: $S_1$ is "0", so if $n=1$, return '0'.

Time Complexity: O(n) - Each recursive call reduces $n$ by 1.
Space Complexity: O(n) - Due to the recursion stack.
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;
        
        if (k == mid) return '1';
        if (k < mid) return findKthBit(n - 1, k);
        
        char c = findKthBit(n - 1, len - k + 1);
        return c == '0' ? '1' : '0';
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.findKthBit(3, 1) << endl; // Output: "0"
    cout << solution.findKthBit(4, 11) << endl; // Output: "1"

    return 0;
}