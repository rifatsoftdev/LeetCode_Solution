#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Keyboard Row:
    1. Define three strings representing the characters in each row of a QWERTY keyboard.
    2. For each word in the input list, iterate through its characters and check which row they belong to.
    3. Keep track of the count of characters belonging to the first, second, and third rows.
    4. If all characters of a word belong to the same row (i.e., the count for that row equals the word's length), add the word to the result list.

Time Complexity: O(n * m), where n is the number of words and m is the average length of a word.
Space Complexity: O(1) (excluding the output vector).
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string first = "qwertyuiop";
        string second = "asdfghjkl";
        string third = "zxcvbnm";

        vector<string> ans;

        for (string word : words) {
            int topCount = 0, secCount = 0, thirdCount = 0;

            for (char c : word) {
                if (first.find(tolower(c)) != string::npos) {
                    topCount++;
                } else if (second.find(tolower(c)) != string::npos) {
                    secCount++;
                } else if (third.find(tolower(c)) != string::npos) {
                    thirdCount++;
                }
            }

            if (topCount == word.size() || secCount == word.size() || thirdCount == word.size()) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<string> words1 = {"Hello","Alaska","Dad","Peace"};
    vector<string> ans1 = solution.findWords(words1);
    printVec(ans1);

    vector<string> words2 = {"omk"};
    vector<string> ans2 = solution.findWords(words2);
    printVec(ans2);

    vector<string> words3 = {"adsdf","sfd"};
    vector<string> ans3 = solution.findWords(words3);
    printVec(ans3);

    return 0;
}