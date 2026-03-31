#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

String Compression:
    1. Iterate through the input character array to identify groups of consecutive identical characters.
    2. For each group, append the character to a result string.
    3. If the group's length is greater than 1, append the length as a string to the result.
    4. Modify the original `chars` array in-place using the characters from the result string.
    5. Return the length of the compressed string.

Time Complexity: O(n) where n is the length of the input array.
Space Complexity: O(n) to store the intermediate compressed string.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";
        int count = 1;

        for (int i = 0; i < chars.size(); i++) {
            if (i == chars.size()-1 || chars[i] != chars[i+1]) {
                ans.push_back(chars[i]);
                if (count > 1)
                    ans += to_string(count);
                count = 1;
            } else {
                count++;
            }
        }
        
        int j = 0;
        
        while (j < ans.size()) {
            chars[j] = ans[j];
            j++;
        }

        if (j < chars.size())
            chars[j] = '\0';

        return ans.size();
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<char> chars1 = {'a','a','b','b','c','c','c'};
    cout << solution.compress(chars1) << endl;

    vector<char> chars2 = {'a'};
    cout << solution.compress(chars2) << endl;

    vector<char> chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout << solution.compress(chars3) << endl;

    return 0;
}