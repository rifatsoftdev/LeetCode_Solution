#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int countOperations(int num1, int num2) {
        int stap = 0;

        while (num1 && num2) {
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }

            stap++;
        }

        return stap;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.countOperations(2, 3) << endl;

    // test cases 2
    cout << solution.countOperations(10, 10) << endl;

    return 0;
}