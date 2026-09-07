#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.




class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;

        for (char c : s) {
            rows[row] += c;

            if (row == 0) {
                direction = 1;
            }
            else if (row == numRows - 1) {
                direction = -1;
            }

            row += direction;
        }

        string result;

        for (string &r : rows) {
            result += r;
        }

        return result;
    }
};



int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << solution.convert(s1, numRows1) << endl;

    // test cases 2
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << solution.convert(s2, numRows2) << endl;

    // test cases 3
    string s3 = "A";
    int numRows3 = 1;
    cout << solution.convert(s3, numRows3) << endl;

    return 0;
}