#include <iostream>
#include <vector>
#include <unordered_set>
#include "../devlibs/cpphelper.h"

using namespace std;


/*
Brute Force Approach:
1. Generate all possible binary codes of size k (there are 2^k such codes).
2. For each generated code, check if it is a substring of s.
3. If any code is not found in s, return false. If all codes are found, return true.

Time Complexity: O(2^k * n) where n is the length of the string s (due to the substring search).
Space Complexity: O(2^k) for storing the generated binary codes.
*/

// class Solution {
// public:
//     vector<string> generateBinary(int k) {
//         int n = 1 << k;  // 2^k combinations
//         vector<string> result;

//         for(int i = 0; i < n; i++) {
//             string s = "";
//             for(int j = k-1; j >= 0; j--) {
//                 s += ((i >> j) & 1) ? '1' : '0';
//             }
//             result.push_back(s);
//         }

//         return result;
//     }

//     bool hasAllCodes(string s, int k) {
//         vector<string> bin = generateBinary(k);

//         for (int i = 0; i < bin.size(); i++) {
//             if (s.find(bin[i]) == string::npos) return false;
//         }

//         return true;
//     }
// };


/*
Optimized Approach:
1. Use a hash set to store all unique substrings of size k found in s.
2. Iterate through the string s and add each substring of size k to the set.
3. After processing, check if the size of the set is equal to 2^k (the total number of possible binary codes of size k).
4. If they are equal, return true; otherwise, return false.

Time Complexity: O(n) where n is the length of the string s (due to the single pass to collect substrings).
Space Complexity: O(2^k) for storing the unique substrings in the hash set.
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> seen;
        int n = s.size();
        
        for(int i = 0; i <= n - k; i++) {
            seen.insert(s.substr(i, k));
        }
        
        return seen.size() == (1 << k);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    cout << solution.hasAllCodes("00110110", 2) << endl;
    cout << solution.hasAllCodes("0110", 1) << endl;
    cout << solution.hasAllCodes("0110", 2) << endl;

    return 0;
}