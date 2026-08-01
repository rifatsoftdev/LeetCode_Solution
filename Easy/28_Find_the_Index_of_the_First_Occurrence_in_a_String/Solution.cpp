#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        int haystackLength = haystack.length();
        int needleLength = needle.length();

        if (needleLength == 0) {
            return 0;
        }
        if (haystackLength < needleLength) {
            return -1;
        }

        for (int i = 0; i <= haystackLength - needleLength; i++) {
            int j;

            for (j = 0; j < needleLength; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }

            if (j == needleLength) {
                index = i;
                break;
            }
        }
        
        return index;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string haystack1 = "sadbutsad", needle1 = "sad";
    cout << solution.strStr(haystack1, needle1) << endl; // Output: 0

    // test cases 2
    string haystack2 = "leetcode", needle2 = "leeto";
    cout << solution.strStr(haystack2, needle2) << endl; // Output: -1


    return 0;
}