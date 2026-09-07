#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int m = n;

        while (n != 0) {
            int d = n % 10;

            sum += d;
            if (d != 0)
                pro *= d;

            n /= 10;
        }
        
        return m % (sum + pro) == 0;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.checkDivisibility(99) << endl;

    // test cases 2
    cout << solution.checkDivisibility(23) << endl;

    return 0;
}