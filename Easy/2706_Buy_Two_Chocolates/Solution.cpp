#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int price : prices) {
            if (price < firstMin) {
                secondMin = firstMin;
                firstMin = price;
            }
            else if (price < secondMin) {
                secondMin = price;
            }
        }

        int cost = firstMin + secondMin;

        if (cost <= money) {
            return money - cost;
        }

        return money;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    vector<int> prices1 = {1,2,2};
    int money1 = 3;
    cout << solution.buyChoco(prices1, money1) << endl;

    // test cases 2
    vector<int> prices2 = {3,2,3};
    int money2 = 3;
    cout << solution.buyChoco(prices2, money2) << endl;

    return 0;
}