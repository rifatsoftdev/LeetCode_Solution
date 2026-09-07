#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;

        if (n % 2 == 1) {
            result.push_back(0);
        }

        for (int i = 1; i <= n / 2; ++i) {
            result.push_back(i);
            result.push_back(-i);
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    int n1 = 5;
    vector<int> result1 = solution.sumZero(n1);
    printVec(result1);

    // test cases 2
    int n2 = 3;
    vector<int> result2 = solution.sumZero(n2);
    printVec(result2);

    // test cases 3
    int n3 = 1;
    vector<int> result3 = solution.sumZero(n3);
    printVec(result3);

    return 0;
}