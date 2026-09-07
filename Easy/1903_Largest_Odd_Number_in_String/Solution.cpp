#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string largestOddNumber(string num) {
        string result = "";

        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                result = num.substr(0, i + 1);
                break;
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string num1 = "52";
    string result1 = solution.largestOddNumber(num1);
    cout << result1 << endl; // Expected output: "5"

    // test cases 2
    string num2 = "4206";
    string result2 = solution.largestOddNumber(num2);
    cout << result2 << endl; // Expected output: ""

    // test cases 3
    string num3 = "35427";
    string result3 = solution.largestOddNumber(num3);
    cout << result3 << endl; // Expected output: "35427"

    return 0;
}