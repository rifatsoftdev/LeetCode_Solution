#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for (char ch : chars) {
            freq[ch - 'a']++;
        }

        int ans = 0;
        for (string word : words) {
            vector<int> temp = freq;
            bool good = true;
            for (char ch : word) {
                if (--temp[ch - 'a'] < 0) {
                    good = false;
                    break;
                }
            }
            if (good) ans += word.size();
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<string> words1 = {"cat", "bt", "hat", "tree"};
    string chars1 = "atach";
    cout << solution.countCharacters(words1, chars1) << endl; // Output: 6
    
    // test cases 2
    vector<string> words2 = {"hello", "world", "leetcode"};
    string chars2 = "welldonehoneyr";
    cout << solution.countCharacters(words2, chars2) << endl; // Output: 10
    
    return 0;
}