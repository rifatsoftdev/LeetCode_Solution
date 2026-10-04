#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;

        for (const string& operation : operations) {
            if (operation == "++X" || operation == "X++") {
                ans++;
            } else if (operation == "--X" || operation == "X--") {
                ans--;
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<string> operations1 = {"--X", "X++", "X++"};
    int result1 = solution.finalValueAfterOperations(operations1);
    cout << result1 << endl;

    // test cases 2
    vector<string> operations2 = {"++X", "++X", "X++"};
    int result2 = solution.finalValueAfterOperations(operations2);
    cout << result2 << endl;

    // test cases 3
    vector<string> operations3 = {"X++", "++X", "--X", "X--"};
    int result3 = solution.finalValueAfterOperations(operations3);
    cout << result3 << endl;

    return 0;
}