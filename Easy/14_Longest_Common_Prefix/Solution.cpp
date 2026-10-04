#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());

        const string& first = strs.front();
        const string& last = strs.back();
        int i = 0;

        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            ++i;
        }

        return first.substr(0, i);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs1) << endl;

    // test cases 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs2) << endl;

    return 0;
}