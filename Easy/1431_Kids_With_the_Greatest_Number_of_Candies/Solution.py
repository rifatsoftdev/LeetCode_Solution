from typing import List, Optional


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxC = max(candies)
        ans = []

        for i in candies:
            if (i+extraCandies >= maxC):
                ans.append(True)
            else:
               ans.append(False)

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    candies1 = [2,3,5,1,3]
    extraCandies1 = 3
    print(solution.kidsWithCandies(candies1, extraCandies1))

    # test cases 2
    candies2 = [4,2,1,1,2]
    extraCandies2 = 1
    print(solution.kidsWithCandies(candies2, extraCandies2))

    # test cases 3
    candies3 = [12,1,12]
    extraCandies3 = 10
    print(solution.kidsWithCandies(candies3, extraCandies3))