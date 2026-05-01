#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Sort Vowels in a String:
    1. Identify all vowels in the given string and store them in a separate list.
    2. Sort the list of vowels in ascending order based on their ASCII values.
    3. Iterate through the original string again. If the character at the current position is a vowel, replace it with the next available vowel from the sorted list.
    4. If the character is a consonant, keep it as it is.

Time Complexity: O(n log n) due to sorting the vowels, where n is the length of the string.
Space Complexity: O(n) to store the vowels and the resulting string.
*/

class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string sortVowels(string s) {
        vector<char> vowels;

        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end());
        string result;
        int j = 0;

        for (char c : s) {
            if (isVowel(c)) {
                result += vowels[j++];
            } else {
                result += c;
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.sortVowels("lEetcOde") << endl;
    cout << solution.sortVowels("lYmpH") << endl;

    return 0;
}