#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Check if Numbers Are Ascending in a Sentence:
    1. Iterate through the sentence and extract all the numbers present in it.
    2. A number is identified as a contiguous sequence of digits.
    3. Store these numbers in a list in the order they appear.
    4. Check if the list of numbers is strictly increasing (each number is greater than the previous one).
    5. Return true if they are strictly increasing, otherwise return false.

Time Complexity: O(n), where n is the length of the string s.
Space Complexity: O(n) to store the extracted numbers.
*/

class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> num;
        string numstr = "";

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                numstr += s[i];
            } else {
                if (numstr != "") {
                    num.push_back(stoi(numstr));
                    numstr = "";
                }
            }
        }

        if (numstr != "") {
            num.push_back(stoi(numstr));
        }
        
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i] >= num[i + 1]) return false;
        }
        
        return true;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    cout << solution.areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles") << endl;
    cout << solution.areNumbersAscending("hello world 5 x 5") << endl;
    cout << solution.areNumbersAscending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s") << endl;

    return 0;
}