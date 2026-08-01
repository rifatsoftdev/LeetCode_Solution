#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = s.length() - 1;

        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;

        vector<string> words;
        string word;
        for (int i = start; i <= end; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result;
        for (size_t i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += ' ';
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
    string s1 = "the sky is blue";
    cout << solution.reverseWords(s1) << endl; // Output: "blue is sky the"

    // test cases 2
    string s2 = "  hello world  ";
    cout << solution.reverseWords(s2) << endl; // Output: "world hello"

    return 0;
}