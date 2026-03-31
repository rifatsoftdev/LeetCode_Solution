#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Roman to Integer:
    1. Create a map to store the integer values of Roman numerals: I=1, V=5, X=10, L=50, C=100, D=500, M=1000.
    2. Iterate through the string from left to right.
    3. For each character, compare its value with the value of the next character.
    4. If the current value is less than the next value, it means a subtraction case (like IV or IX), so subtract the current value from the total.
    5. Otherwise, add the current value to the total.
    6. Return the final total.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as the map size is constant (7 Roman numerals).
*/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (m[s[i]] < m[s[i + 1]]) total -= m[s[i]];
            else total += m[s[i]];
        }

        return total;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.romanToInt("III") << endl;
    cout << solution.romanToInt("LVIII") << endl;
    cout << solution.romanToInt("MCMXCIV") << endl;

    return 0;
}