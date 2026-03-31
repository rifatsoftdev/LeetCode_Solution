#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Integer to Roman:
    1. Create a mapping of integer values to their corresponding Roman numeral strings, including special subtraction cases (4, 9, 40, 90, 400, 900).
    2. Iterate through the mapping in descending order of values.
    3. While the current number is greater than or equal to the value in the mapping, append the Roman numeral to the result and subtract the value from the number.
    4. Return the resulting string.

Time Complexity: O(1), since the number of Roman numeral symbols is constant and the input range is limited (up to 3999).
Space Complexity: O(1), as the mapping size is constant.
*/

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };

        string ans = "";

        for (auto it = m.rbegin(); it != m.rend(); it++) {
            while (num >= it->first) {
                ans += it->second;
                num -= it->first;
            }
        }

        return ans;  
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.intToRoman(3749) << endl;
    cout << solution.intToRoman(58) << endl;
    cout << solution.intToRoman(1994) << endl;

    return 0;
}