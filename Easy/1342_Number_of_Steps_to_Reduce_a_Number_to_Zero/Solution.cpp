#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;

        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num -= 1;
            }
            steps++;
        }

        return steps;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.numberOfSteps(14) << endl; // Output: 6

    // test cases 2
    cout << solution.numberOfSteps(8) << endl;  // Output: 4

    // test cases 3
    cout << solution.numberOfSteps(123) << endl; // Output: 12

    return 0;
}