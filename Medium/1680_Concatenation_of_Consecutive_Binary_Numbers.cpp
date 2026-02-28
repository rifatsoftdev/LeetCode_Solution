#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Optimal Substructure:
1. We can iterate through the numbers from 1 to n and keep track of the current bit length of the numbers we are concatenating.
2. For each number i, we check if it is a power of 2 (i.e., if (i & (i - 1)) == 0). If it is, we increment the bit length since the next number will require an additional bit to represent.
3. We then left shift the current result by the current bit length (to make space for the new number) and add the current number i to the result.
4. We take the result modulo 10^9 + 7 to prevent overflow and ensure we return the correct result.

Time Complexity: O(N) - We iterate through the numbers from 1 to n once, performing constant time operations for each number.
Space Complexity: O(1) - We use a constant amount of space to store the result and the bit length.
*/

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int bitLength = 0;

        for (int i = 1; i <= n; i++) {

            // if i is power of 2
            if ((i & (i - 1)) == 0)
                bitLength++;

            result = ((result << bitLength) % MOD + i) % MOD;
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.concatenatedBinary(1) << endl; // Output: 1
    cout << solution.concatenatedBinary(3) << endl; // Output: 27
    cout << solution.concatenatedBinary(12) << endl; // Output: 505379714

    return 0;
}