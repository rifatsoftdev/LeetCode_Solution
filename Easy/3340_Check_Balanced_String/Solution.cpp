#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.

class Solution {
public:
    bool isBalanced(string num) {
        int evenSum = 0;
        int oddSum = 0;

        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';
            if (i % 2 == 0) {
                evenSum += digit;
            } else {
                oddSum += digit;
            }
        }
        
        return evenSum == oddSum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    // test cases 1
    cout << solution.isBalanced("1234") << endl; // Output: false

    // test cases 2
    cout << solution.isBalanced("24123") << endl;  // Output: true

    return 0;
}