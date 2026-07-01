#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int secondHighest(string s) {
        int fastLarge = -1;
        int secendLarge = -1;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';

                if (num > fastLarge) {
                    secendLarge = fastLarge;
                    fastLarge = num;
                } else if (num < fastLarge && num > secendLarge) {
                    secendLarge = num;
                }
            }
        }

        return secendLarge;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.secondHighest("dfa12321afd") << endl;

    // test cases 2
    cout << solution.secondHighest("abc1111") << endl;

    return 0;
}