#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
                right--;
            } else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                else {
                    left++;
                    right--;
                }
            }
        }

        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(s1) << endl;

    // test cases 2
    string s2 = "race a car";
    cout << solution.isPalindrome(s2) << endl;

    // test cases 3
    string s3 = " ";
    cout << solution.isPalindrome(s3) << endl;

    return 0;
}