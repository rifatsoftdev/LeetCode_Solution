#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Prime Number of Set Bits in Binary Representation:
    1. Count the number of set bits in the binary representation of each number in the range [left, right].
    2. Check if the count of set bits is a prime number.
    3. Return the total count of numbers that have a prime number of set bits.

Time Complexity: O(n * sqrt(m)), where n is the number of integers in the range [left, right] and m is the maximum number of set bits (which is at most 32 for 32-bit integers).
Space Complexity: O(1), as we are using a constant amount of extra space.
*/

class Solution {
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;

        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);

            if (isPrime(setBits)) {
                count++;
            }
        }

        return count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.countPrimeSetBits(6, 10) << endl; // Output: 4
    cout << solution.countPrimeSetBits(10, 15) << endl; // Output: 5

    return 0;
}