#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int count1 = 0, count2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (isVowel(s[i])) {
                count1++;
            }
        }

        for (int i = n / 2; i < n; i++) {
            if (isVowel(s[i])) {
                count2++;
            }
        }

        return count1 == count2;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    cout << solution.halvesAreAlike("book") << endl; // true

    // test cases 2
    cout << solution.halvesAreAlike("textbook") << endl; // false

    return 0;
}