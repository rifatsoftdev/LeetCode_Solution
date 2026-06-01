#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even_count = 0;
        int odd_count = 0;

        for (int i : position) {
            if (i % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        return min(even_count, odd_count);
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> position1 = {1, 2, 3};
    cout << solution.minCostToMoveChips(position1) << endl;

    // test cases 2
    vector<int> position2 = {2, 2, 2, 3, 3};
    cout << solution.minCostToMoveChips(position2) << endl;

    // test cases 3
    vector<int> position3 = {1, 1000000000};
    cout << solution.minCostToMoveChips(position3) << endl;

    return 0;
}