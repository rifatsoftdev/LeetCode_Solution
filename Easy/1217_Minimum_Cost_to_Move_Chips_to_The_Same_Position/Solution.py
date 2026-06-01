from typing import List, Optional


class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        even = 0
        odd = 0

        for i in position:
            if (i % 2 == 0):
                even += 1
            else:
                odd += 1
        
        return min(even, odd)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    position1 = [1,2,3]
    print(solution.minCostToMoveChips(position1))

    # test cases 2
    position2 = [2,2,2,3,3]
    print(solution.minCostToMoveChips(position2))
    
    # test cases 3
    position3 = [1,1000000000]
    print(solution.minCostToMoveChips(position3))