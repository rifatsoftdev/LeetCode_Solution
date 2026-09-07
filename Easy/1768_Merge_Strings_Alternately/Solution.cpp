#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0;
        string result;

        while (i < n && j < m) {
            result += word1[i++];
            result += word2[j++];
        }

        while (i < n) {
            result += word1[i++];
        }

        while (j < m) {
            result += word2[j++];
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    string word1 = "abc";
    string word2 = "pqr";
    string result = solution.mergeAlternately(word1, word2);
    cout << result << endl; // Expected: "apbqcr"

    // test cases 2
    word1 = "ab";
    word2 = "pqrs";
    result = solution.mergeAlternately(word1, word2);
    cout << result << endl; // Expected: "apbqcr"

    // test cases 3
    word1 = "abcd";
    word2 = "pq";
    result = solution.mergeAlternately(word1, word2);
    cout << result << endl; // Expected: "apbqcr"

    return 0;
}