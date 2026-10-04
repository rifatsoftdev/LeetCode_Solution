#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> arr(26);

        for (char c: allowed) {
            arr[c-97] = true;
        }

        int result = 0;

        for (string s: words) {
            bool flag = true;

            for (char c: s) {
                if (!arr[c - 97]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
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
    string allowed1 = "ab";
    vector<string> words1 = {"ad","bd","aaab","baa","badab"};
    cout << solution.countConsistentStrings(allowed1, words1) << endl;

    // test cases 2
    string allowed2 = "abc";
    vector<string> words2 = {"a","b","c","ab","ac","bc","abc"};
    cout << solution.countConsistentStrings(allowed2, words2) << endl;

    // test cases 3
    string allowed3 = "cad";
    vector<string> words3 = {"cc","acd","b","ba","bac","bad","ac","d"};
    cout << solution.countConsistentStrings(allowed3, words3) << endl;

    return 0;
}