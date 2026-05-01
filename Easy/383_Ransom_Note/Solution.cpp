#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Ransom Note:
    1. Count the frequency of each character in the `magazine` string using a hash map or a frequency array.
    2. Iterate through the `ransomNote` string and for each character, check if it exists in the frequency map with a count greater than zero.
    3. If the character is available, decrement its count in the map.
    4. If a character is not available or its count is zero, return false.
    5. If all characters in the `ransomNote` are successfully matched, return true.

Time Complexity: O(m + n), where m is the length of the ransomNote and n is the length of the magazine.
Space Complexity: O(k), where k is the number of unique characters (at most 26 for lowercase English letters).
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> magazineMap;
        for (char c : magazine) {
            magazineMap[c]++;
        }

        for (char c : ransomNote) {
            if (magazineMap[c] == 0) {
                return false;
            }
            magazineMap[c]--;
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}