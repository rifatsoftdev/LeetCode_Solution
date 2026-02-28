#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach:
1. Convert the number to binary string.
2. Iterate through the binary string and count the maximum distance between two consecutive '1's.
Time Complexity: O(log n) (due to the conversion to binary)
Space Complexity: O(log n) (due to the binary string)
*/

// class Solution {
// public:
//     string decimalToBinary(int n) {
//         if (n == 0) return "0";

//         string binstr = "";
//         while (n > 0) {
//             int remainder = n % 2;
//             binstr += to_string(remainder);
//             n /= 2;
//         }
//         reverse(binstr.begin(), binstr.end());
//         return binstr;
//     }

//     int binaryGap(int n) {
//         string bin = decimalToBinary(n);

//         int last = -1;
//         int maxGap = 0;

//         for (int i = 0; i < bin.size(); i++) {
//             if (bin[i] == '1') {
//                 if (last != -1) {
//                     maxGap = max(maxGap, i - last);
//                 }
//                 last = i;
//             }
//         }

//         return maxGap;
//     }
// };


/*
Optimal Approach (Bit Manipulation):
1. Use bit manipulation to find the positions of '1's in the binary representation of the number.
2. Calculate the maximum distance between two consecutive '1's.

Time Complexity: O(log n) (due to the number of bits in n)
Space Complexity: O(1)
*/

class Solution {
public:
    int binaryGap(int n) {
        int lastIndex = -1;
        int maxGap = 0;
        int index = 0;

        while (n > 0) {
            if (n & 1) {
                if (lastIndex != -1) {
                    maxGap = max(maxGap, index - lastIndex);
                }
                lastIndex = index;
            }
            n >>= 1;  // right shift
            index++;
        }

        return maxGap;
    }
};


int main() {
    Solution solution;

    cout << solution.binaryGap(22) << endl;
    cout << solution.binaryGap(8) << endl;
    cout << solution.binaryGap(5) << endl;
    cout << solution.binaryGap(6) << endl;

    return 0;
}