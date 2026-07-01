from typing import List, Optional


class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()

        count = 0

        for cost in costs:
            if (coins < cost):
                break

            coins -= cost
            count += 1
        
        return count


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    costs1 = [1,3,2,4,1]
    coins1 = 7
    print(solution.maxIceCream(costs1, coins1))

    # test cases 2
    costs2 = [10,6,8,7,7,8]
    coins2 = 5
    print(solution.maxIceCream(costs2, coins2))

    # test cases 3
    costs3 = [1,6,3,1,2,5]
    coins3 = 20
    print(solution.maxIceCream(costs3, coins3))
    
    