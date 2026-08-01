from typing import List, Optional


class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        
        for i in range(n):
            if n % (i + 1) == 0:
                ans += nums[i] * nums[i]
        
        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 2, 3, 4]
    print(solution.sumOfSquares(nums1))

    # test cases 2
    nums2 = [2, 7, 1, 19, 18, 3]
    print(solution.sumOfSquares(nums2))
    