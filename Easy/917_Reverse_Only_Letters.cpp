#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Reverse Only Letters:
    1. Initialize two pointers, left and right, to the start and end of the string, respectively.
    2. While left is less than right:
    a. If the character at left is not a letter, move the left pointer to the right.
    b. If the character at right is not a letter, move the right pointer to the left.
    c. If both characters are letters, swap them and move both pointers towards the center.
    3. Return the modified string.

Time Complexity: O(n), where n is the length of the string, since we may need to traverse the string once.
Space Complexity: O(1), since we are modifying the string in place and not using any additional data structures that grow with the input size.
*/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (!isalpha(s[left])) {
                left++;
            } else if (!isalpha(s[right])) {
                right--;
            } else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.reverseOnlyLetters("ab-cd") << endl;
    cout << solution.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
    cout << solution.reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;

    return 0;
}