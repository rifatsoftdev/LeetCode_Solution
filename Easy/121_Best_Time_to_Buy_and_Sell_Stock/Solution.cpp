#include "../../devlibs/cpp/cpphelper.h"


using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.

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