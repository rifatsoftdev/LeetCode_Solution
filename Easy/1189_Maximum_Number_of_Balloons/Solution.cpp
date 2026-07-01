#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;

        for (char c : text) {
            freq[c]++;
        }

        return min(freq['b'], min(freq['a'],  min(freq['l'] / 2, min(freq['o'] / 2, freq['n']))));
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string text1 = "nlaebolko";
    cout << solution.maxNumberOfBalloons(text1) << endl;

    // test cases 2
    string text2 = "loonbalxballpoon";
    cout << solution.maxNumberOfBalloons(text2) << endl;

    // test cases 3
    string text3 = "leetcode";
    cout << solution.maxNumberOfBalloons(text3) << endl;

    return 0;
}