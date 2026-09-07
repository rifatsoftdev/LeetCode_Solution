#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int smallestNumber(int n, int t) {
        int current = n;

        while (true) {
            int product = 1;
            int temp = current;

            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }

            if (product % t == 0) {
                return current;
            }

            current++;
        }
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.smallestNumber(10, 2) << endl; // Expected output: 10

    // test cases 2
    cout << solution.smallestNumber(15, 3) << endl; // Expected output: 16

    return 0;
}