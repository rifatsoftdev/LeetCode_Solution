#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int totalCost = 0;

        if (n < 3) {
            for (int c : cost) totalCost += c;
            return  totalCost;
        }

        sort(cost.begin(), cost.end(), greater<int>());

        for (int i = 0; i < n; i++) {
            if (i % 3 == 2) continue;
            totalCost += cost[i];
        }

        return totalCost;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> cost1 = {1, 2, 3};
    cout << solution.minimumCost(cost1) << endl; // Output: 5

    // test cases 2
    vector<int> cost2 = {6, 5, 7, 9, 2, 2};
    cout << solution.minimumCost(cost2) << endl; // Output: 23

    // test cases 3
    vector<int> cost3 = {5, 5};
    cout << solution.minimumCost(cost3) << endl; // Output: 10

    return 0;
}