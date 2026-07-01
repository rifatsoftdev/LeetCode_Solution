#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxNum = 0;
        int prefixSum = 0;

        for (int i = 0; i < gain.size(); i++) {
            prefixSum += gain[i];
            maxNum = max(maxNum, prefixSum);
        }

        return maxNum;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> gain1 = {-5,1,5,0,-7};
    cout << solution.largestAltitude(gain1) << endl;

    // test cases 2
    vector<int> gain2 = {-4,-3,-2,-1,4,3,2};
    cout << solution.largestAltitude(gain2) << endl;

    return 0;
}