#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

String to Integer (atoi):
    1. Discard any leading whitespace.
    2. Check for an optional sign ('+' or '-').
    3. Read the next characters until the first non-digit character or the end of the string is reached.
    4. Convert these digits into an integer.
    5. Handle overflow: if the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], clamp it to INT_MIN or INT_MAX.

Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(1)
*/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * result);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.myAtoi("42") << endl;
    cout << solution.myAtoi(" -042") << endl;
    cout << solution.myAtoi("1337c0d3") << endl;
    cout << solution.myAtoi("0-1") << endl;
    cout << solution.myAtoi("words and 987") << endl;

    return 0;
}