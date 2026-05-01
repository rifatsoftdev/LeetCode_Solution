#include "../devlibs/cpphelper.h"


using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Best Time to Buy and Sell Stock (Optimal):
    1. Initialize `minPrice` to a very large value and `maxProfit` to 0.
    2. Iterate through the `prices` array:
        a. If the current price is less than `minPrice`, update `minPrice`.
        b. Otherwise, calculate the potential profit (current price - `minPrice`) and update `maxProfit` if this profit is greater than the current `maxProfit`.
    3. Return `maxProfit`.

Time Complexity: O(n) (where n is the number of days/prices)
Space Complexity: O(1)

Note: This approach uses a single pass to find the minimum price seen so far and the maximum difference that follows it.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
};




/* ================================================================================
Solution 2:


*/

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
        
//     }
// };


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << solution.maxProfit(prices1) << endl;

    vector<int> prices2 = {7,6,4,3,1};
    cout << solution.maxProfit(prices2) << endl;

    return 0;
}