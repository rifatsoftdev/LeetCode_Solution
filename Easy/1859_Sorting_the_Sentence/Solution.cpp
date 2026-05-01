#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Sorting the Sentence:
    1. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
    2. A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
    3. To reconstruct the original sentence, iterate through the shuffled string and extract each word along with its position.
    4. Use a map or an array to store words at their respective indices.
    5. Concatenate the words in the correct order, separated by spaces, to form the original sentence.

Time Complexity: O(n), where n is the length of the string s.
Space Complexity: O(n) to store the words in the map and the final result.
*/

class Solution {
public:
    string sortSentence(string s) {
        map<int, string> m;
        int n = s.size();
        string temp = "";

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int j = s[i] - '0';
                m[j] = temp;
                temp = "";
            } else if (s[i] != ' ') {
                temp += s[i];
            }
        }

        string ans = "";

        for (int i = 0; i < m.size(); i++) {
            ans += m[i + 1];
            if (i != m.size() - 1) {
                ans += " ";
            }
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.sortSentence("is2 sentence4 This1 a3") << endl;
    cout << solution.sortSentence("Myself2 Me1 I4 and3") << endl;

    return 0;
}