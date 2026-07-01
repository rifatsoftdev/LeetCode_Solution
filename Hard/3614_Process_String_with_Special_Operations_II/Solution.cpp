#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    char processStr(string s, long long k) {
        long long m = 0;

        // Final length
        for (char c : s) {
            if (c == '*') {
                m = max(0LL, m - 1);
            } else if (c == '#') {
                m *= 2;
            } else if (c != '%') {
                m++;
            }
        }

        if (k >= m) return '.';

        // Reverse simulation
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c == '*') {
                m++;
            }
            else if (c == '#') {
                m /= 2;
                if (k >= m) k -= m;
            }
            else if (c == '%') {
                k = m - 1 - k;
            }
            else { // letter
                m--;
                if (k == m) return c;
            }
        }

        return '.';
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "a#b%*";
    int k1 = 1;
    cout << solution.processStr(s1, k1) << endl;
    
    // test cases 2
    string s2 = "cd%#*#";
    int k2 = 3;
    cout << solution.processStr(s2, k2) << endl;

    // test cases 3
    string s3 = "z*#";
    int k3 = 0;
    cout << solution.processStr(s3, k3) << endl;
    
    // test cases 4
    string s4 = "fwp*m*#a%%";
    int k4 = 5;
    cout << solution.processStr(s4, k4) << endl;

    return 0;
}