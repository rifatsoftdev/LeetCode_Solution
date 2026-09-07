#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int firstMatchingIndex(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            if (s[left] == s[right]) {
                return left;
            }

            left++;
            right--;
        }

        return -1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "abcacbd";
    cout << solution.firstMatchingIndex(s1) << endl;

    // test cases 2
    string s2 = "abc";
    cout << solution.firstMatchingIndex(s2) << endl;

    // test cases 3
    string s3 = "abcdab";
    cout << solution.firstMatchingIndex(s3) << endl;

    return 0;
}