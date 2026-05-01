#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Generate parentheses:
    1. If the number of left parentheses is less than n, we can add a left parenthesis.
    2. If the number of left parentheses is greater than the number of right parentheses, we can add a right parenthesis.

Time complexity: O(2^n) - In the worst case, we can generate all possible combinations of parentheses, which is 2^n.
Space complexity: O(n) - The maximum depth of the recursion is n, which is the length of the longest valid parentheses string we can generate.
*/

class Solution {
    void parentheses(int n, int left, int right, vector<string> &ans, string &temp) {
        if (left+right == 2*n) {
            ans.push_back(temp);
            return;
        }

        if (left < n) {
            temp.push_back('(');
            parentheses(n, left+1, right, ans, temp);
            temp.pop_back();
        }
        if (left > right) {
            temp.push_back(')');
            parentheses(n, left, right+1, ans, temp);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        parentheses(n, 0, 0, ans, temp);
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}