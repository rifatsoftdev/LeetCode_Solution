#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    int sumOfDrgit(int n) {
        int ans = 0;

        while (n != 0) {
            int digit = n % 10;
            ans += digit;
            n /= 10;
        }

        return ans;
    }

public:
    int countEven(int num) {
        int ans = 0;

        for (int i = 2; i <= num; i++) {
            int n = sumOfDrgit(i);
            if (n % 2 == 0) ans++;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.countEven(4) << endl;

    // test cases 2
    cout << solution.countEven(30) << endl;

    return 0;
}