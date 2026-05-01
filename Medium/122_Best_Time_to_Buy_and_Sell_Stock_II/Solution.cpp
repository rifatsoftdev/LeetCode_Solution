#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Best Time to Buy and Sell Stock II (Greedy):
    1. Iterate through the price array and identify every instance where the price increases from one day to the next.
    2. Since we can buy and sell on the same day, the total maximum profit is the sum of all positive differences between consecutive days.
    3. This approach captures all upward price movements, which is equivalent to buying at every local minimum and selling at every local maximum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        for (int i = 0; i < n-1; i++) {
            if (prices[i] < prices[i+1]) {
                ans += prices[i+1]-prices[i];
            }
        }
        return ans;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << solution.maxProfit(prices1) << endl;

    vector<int> prices2 = {1,2,3,4,5};
    cout << solution.maxProfit(prices2) << endl;

    vector<int> prices3 = {7,6,4,3,1};
    cout << solution.maxProfit(prices3) << endl;

    return 0;
}