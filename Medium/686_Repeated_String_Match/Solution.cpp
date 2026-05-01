#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Repeated String Match:
    1. Repeat string `a` until its length is at least the length of string `b`.
    2. Check if `b` is a substring of the current repeated string. If yes, return the number of repetitions.
    3. If not, append `a` one more time and check again. This handles cases where `b` might be split across the boundary of the repeated string.
    4. If `b` is still not found, it's impossible for `b` to be a substring, so return -1.

Time Complexity: O(n * m) where n is the length of `a` and m is the length of `b`.
Space Complexity: O(n + m) to store the repeated string.
*/

class Solution {
private:
    int kmp_match(string haystack, string needle) {
        int index = -1;
        int haystackLength = haystack.length();
        int needleLength = needle.length();

        if (needleLength == 0) return 0;
        if (haystackLength < needleLength) return -1;

        for (int i = 0; i <= haystackLength - needleLength; i++) {
            int j;

            for (j = 0; j < needleLength; j++) {
                if (haystack[i + j] != needle[j]) break;
            }
            
            if (j == needleLength) return 1;
        }

        return 0;
    }

public:
    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;

        int repeat = 1;
        string temp = a;

        while (temp.size() < b.size()) {
            temp += a;
            repeat += 1;
        }

        if (kmp_match(temp, b) == 1) return repeat;

        if (kmp_match(temp+a, b) == 1) return repeat+1;

        return -1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.repeatedStringMatch("abcd", "cdabcdab") << endl;
    cout << solution.repeatedStringMatch("a", "aa") << endl;

    return 0;
}