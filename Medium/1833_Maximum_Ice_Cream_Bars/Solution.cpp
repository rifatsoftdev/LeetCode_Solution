#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {
            if (coins < cost) break;

            coins -= cost;
            count++;
        }

        return count;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> costs1 = {1,3,2,4,1};
    int coins1 = 7;
    cout << solution.maxIceCream(costs1, coins1) << endl;

    // test cases 2
    vector<int> costs2 = {10,6,8,7,7,8};
    int coins2 = 5;
    cout << solution.maxIceCream(costs2, coins2) << endl;

    // test cases 3
    vector<int> costs3 = {1,6,3,1,2,5};
    int coins3 = 20;
    cout << solution.maxIceCream(costs3, coins3) << endl;

    return 0;
}