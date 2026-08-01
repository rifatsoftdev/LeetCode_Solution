from typing import Optional, List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        profit = 0

        for i in range(1, len(prices)):
            cur_profit = prices[i] - min_price
            if (cur_profit > profit):
                profit = cur_profit
            min_price = min(min_price, prices[i])
        
        return profit



if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    prices1 = [7,1,5,3,6,4]
    print(solution.maxProfit(prices1))

    # test cases 2
    prices2 = [7,6,4,3,1]
    print(solution.maxProfit(prices2))