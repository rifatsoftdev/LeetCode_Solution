#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> freqS;
        unordered_map<char, int> freqT;

        for (char c : s) {
            freqS[c]++;
        }

        for (char c : target) {
            freqT[c]++;
        }

        int minNum = INT_MAX;

        for (const auto& pair : freqT) {
            minNum = min(minNum, freqS[pair.first] / pair.second);
        }

        return minNum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string s1 = "ilovecodingonleetcode", target1 = "code";
    cout << solution.rearrangeCharacters(s1, target1) << endl;

    // test cases 2
    string s2 = "abcba", target2 = "abc";
    cout << solution.rearrangeCharacters(s2, target2) << endl;

    // test cases 3
    string s3 = "abbaccaddaeea", target3 = "aaaaa";
    cout << solution.rearrangeCharacters(s3, target3) << endl;

    return 0;
}