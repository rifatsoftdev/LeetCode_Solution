from typing import List, Optional


class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        nums.sort()

        return (nums[-1] - 1) * (nums[-2] - 1)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [3, 4, 5, 2]
    print(solution.maxProduct(nums1))  # Output: 12
    
    # test cases 2
    nums2 = [1, 5, 4, 5]
    print(solution.maxProduct(nums2))  # Output: 16
    