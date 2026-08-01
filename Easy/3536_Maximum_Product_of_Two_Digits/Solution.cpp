#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxProduct(int n) {
        int firstLarge = 0;
        int secondLarge = 0;

        while (n != 0) {
            int digit = n % 10;

            if (digit > firstLarge) {
                secondLarge = firstLarge;
                firstLarge = digit;
            }
            else if (digit > secondLarge) {
                secondLarge = digit;
            }
            
            n /= 10;
        }

        return firstLarge * secondLarge;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    int n1 = 31;
    cout << solution.maxProduct(n1) << endl;

    // test cases 2
    int n2 = 22;
    cout << solution.maxProduct(n2) << endl;

    int n3 = 124;
    cout << solution.maxProduct(n3) << endl;

    return 0;
}