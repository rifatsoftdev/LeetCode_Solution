import sys
from typing import List


class Solution:
    def minElement(self, nums: List[int]) -> int:
        minSum = sys.maxsize

        for n in nums:
            ds = 0

            while (n != 0):
                d = n % 10
                ds += d
                n = n // 10

            minSum = min(minSum, ds)

        return minSum


if __name__ == "__main__":
    solution = Solution()
    
    # test cases 1
    nums1 = [10,12,13,14]
    print(solution.minElement(nums1))

    # test cases 2
    nums2 = [1,2,3,4]
    print(solution.minElement(nums2))

    # test cases 3
    nums3 = [999,19,199]
    print(solution.minElement(nums3))
        
        