from typing import List, Optional


class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return (nums[-1] * nums[-2]) - (nums[0] * nums[1])


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [5, 6, 2, 7, 4]
    print(solution.maxProductDifference(nums1))  # Output: 34
    
    # test cases 2
    nums2 = [4, 2, 5, 9, 7, 4, 8]
    print(solution.maxProductDifference(nums2))  # Output: 64
    
    
    