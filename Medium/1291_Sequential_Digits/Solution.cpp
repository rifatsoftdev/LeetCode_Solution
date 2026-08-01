#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (int  i = low; i <= high; i++) {
            string s = to_string(i);
            bool isSequential = true;

            for (int j = 0; j < s.size() - 1; j++) {
                if (s[j+1] - s[j] != 1) {
                    isSequential = false;
                    break;
                }
            }
            
            if (isSequential) {
                res.push_back(i);
            }
        }

        return res;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    
    int low1 = 100, high1 = 300;
    auto result1 = solution.sequentialDigits(low1, high1);
    printVec(result1);

    // test cases 2
    int low2 = 1000, high2 = 13000;
    auto result2 = solution.sequentialDigits(low2, high2);
    printVec(result2);
    

    return 0;
}