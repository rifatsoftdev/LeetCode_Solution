#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        int max_odd = 0;
        int min_evn = INT_MAX;

        for (auto const& [val, count] : freq) {
            if (count % 2 != 0) {
                max_odd = max(max_odd, count);
            } else {
                min_evn = min(min_evn, count);
            }
        }

        return max_odd - min_evn;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.maxDifference("aaaaabbc") << endl;     // 3

    // test cases 2
    cout << solution.maxDifference("abcabcab") << endl;     // 1

    return 0;
}