#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans;
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;

            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }
            } else {
                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n];
                }
            }
            
            ans[i] = sum;
        }

        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test case 1
    vector<int> code1 = {5, 7, 1, 4};
    vector<int> result1 = solution.decrypt(code1, 3);
    printVec(result1);

    // test case 2
    vector<int> code2 = {1, 2, 3, 4};
    vector<int> result2 = solution.decrypt(code2, 0);
    printVec(result2);

    // test case 3
    vector<int> code3 = {2, 4, 9, 3};
    vector<int> result3 = solution.decrypt(code3, -2);
    printVec(result3);

    return 0;
}