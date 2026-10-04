#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        int n = s1.size();

        for (int i = n; i <= s2.size(); i++) {
            string s = s2.substr(i - n, n);
            sort(s.begin(), s.end());
            
            if (s1 == s) {
                return true;
            }
        }

        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s11 = "ab";
    string s21 = "eidbaooo";
    cout << solution.checkInclusion(s11, s21) << endl;

    // test cases 2
    string s12 = "ab";
    string s22 = "eidboaoo";
    cout << solution.checkInclusion(s12, s22) << endl;

    return 0;
}