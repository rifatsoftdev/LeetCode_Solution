#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Plus One:
    1. Iterate through the digits from right to left.
    2. If the current digit is less than 9, increment it by 1 and return the array.
    3. If the digit is 9, set it to 0 and continue to the next digit on the left.
    4. If all digits are 9, the loop will finish, and we need to insert a 1 at the beginning of the array.

Time Complexity: O(n)
Space Complexity: O(1) (or O(n) if a new digit is inserted at the front)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int lastValue = digits[digits.size() - 1];

        if (lastValue < 9) {
            digits[digits.size() - 1] = lastValue + 1;
            return digits;
        }

        digits[digits.size() - 1] = 0;

        for (int i = digits.size() - 2; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);

        return digits;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> digits1 = {1,2,3};
    printVec(solution.plusOne(digits1));

    vector<int> digits2 = {4,3,2,1};
    printVec(solution.plusOne(digits2));

    vector<int> digits3 = {9};
    printVec(solution.plusOne(digits3));

    return 0;
}