from typing import List, Optional


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        maxNum = 0
        prefixSum = 0

        for i in range(len(gain)):
            prefixSum += gain[i]
            maxNum = max(maxNum, prefixSum)

        return maxNum


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    gain1 = [-5,1,5,0,-7]
    print(solution.largestAltitude(gain1))

    # test cases 2
    gain2 = [-4,-3,-2,-1,4,3,2]
    print(solution.largestAltitude(gain2))
    