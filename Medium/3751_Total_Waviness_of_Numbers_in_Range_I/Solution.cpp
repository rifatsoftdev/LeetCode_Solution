#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    int waviness(int x) {
        string s = to_string(x);

        if (s.size() < 3) return 0;

        int cnt = 0;

        for (int i = 1; i < s.size() - 1; i++) {
            if ((s[i] > s[i-1] && s[i] > s[i+1]) ||
                (s[i] < s[i-1] && s[i] < s[i+1])) {
                cnt++;
            }
        }

        return cnt;
    }

public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int x = num1; x <= num2; x++) {
            ans += waviness(x);
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.totalWaviness(120, 130) << endl;

    // test cases 2
    cout << solution.totalWaviness(198, 202) << endl;

    // test cases 3
    cout << solution.totalWaviness(4848, 4848) << endl;

    return 0;
}