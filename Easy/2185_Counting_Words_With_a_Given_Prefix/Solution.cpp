#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Counting Words With a Given Prefix:
    1. Iterate through each word in the given list of words.
    2. For each word, check if it starts with the specified prefix.
    3. To check the prefix, compare the characters of the prefix with the beginning of the word. If the word is shorter than the prefix or any character mismatch occurs, it's not a match.
    4. Maintain a counter and increment it for every word that matches the prefix.
    5. Return the final count.

Time Complexity: O(n * m), where n is the number of words and m is the length of the prefix.
Space Complexity: O(1), as we only use a few variables for counting and indexing.
*/

class Solution {
private:
    bool cleck(string& word, string& pref) {
        int n = word.size();
        int m = pref.size();

        if (n < m) return false;

        for (int i = 0; i < m; i++) {
            if (word[i] != pref[i]) {
                return false;
            }
        }
        return true;
    }

public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for (string word : words) {
            if (cleck(word, pref)) {
                ans++;
            }
        }
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<string> words1 = {"pay","attention","practice","attend"};
    cout << solution.prefixCount(words1, "at") << endl; // Output: 2

    vector<string> words2 = {"leetcode","win","loops","success"};
    cout << solution.prefixCount(words2, "code") << endl; // Output: 0

    return 0;
}