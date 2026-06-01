#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.




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