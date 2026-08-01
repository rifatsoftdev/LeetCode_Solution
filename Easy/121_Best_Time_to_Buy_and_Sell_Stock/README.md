# 121_Best_Time_to_Buy_and_Sell_Stock

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