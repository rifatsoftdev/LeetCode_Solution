from typing import List, Optional


class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        firstMin = 100
        secondMin = 100;

        for price in prices:
            if (price < firstMin):
                secondMin = firstMin
                firstMin = price
           
            elif (price < secondMin):
                secondMin = price
         
        cost = firstMin + secondMin

        if (cost <= money):
            return money - cost

        return money


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    prices1 = [1,2,2];
    money1 = 3;
    print(solution.buyChoco(prices1, money1))

    # test cases 2
    prices2 = [3,2,3];
    money2 = 3;
    print(solution.buyChoco(prices2, money2))
    
    