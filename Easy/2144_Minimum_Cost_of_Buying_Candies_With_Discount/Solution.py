from typing import List, Optional


class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)

        total_cost = 0
        for i in range(len(cost)):
            if (i + 1) % 3 != 0:
                total_cost += cost[i]

        return total_cost


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    # test cases 2
    
    