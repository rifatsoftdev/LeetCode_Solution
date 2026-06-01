#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int m = 0;

        for (int i = 2; i < num.size(); i++) {
            if (num[i-2] == num[i-1] && num[i-1] == num[i]) {
                int d = num[i] - '0';

                if (m <= d) {
                    ans = num.substr(i-2, 3);
                    m = d;
                }
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.largestGoodInteger("6777133339") << endl;

    // test cases 2
    cout << solution.largestGoodInteger("2300019") << endl;

    // test cases 3
    cout << solution.largestGoodInteger("42352338") << endl;

    return 0;
}