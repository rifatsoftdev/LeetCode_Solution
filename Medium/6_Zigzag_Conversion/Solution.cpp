#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> stArr[numRows];

        for (int i = 0; i < s.size(); i++) {
            
        }

        string result;
        
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