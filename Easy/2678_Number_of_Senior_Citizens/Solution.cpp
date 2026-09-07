#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;

        for (const auto& detail : details) {
            int age = stoi(detail.substr(11, 2));
            if (age > 60) {
                result++;
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
    vector<string> details1 = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    cout << solution.countSeniors(details1) << endl; // Output: 2

    // test cases 2
    vector<string> details2 = {"1313579440F2036","2921522980M5644"};
    cout << solution.countSeniors(details2) << endl; // Output: 0

    return 0;
}