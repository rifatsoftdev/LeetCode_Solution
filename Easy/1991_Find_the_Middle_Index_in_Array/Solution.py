from typing import List, Optional


class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        total_sum = sum(nums)
        left_sum = 0

        for i, num in enumerate(nums):
            if left_sum == (total_sum - left_sum - num):
                return i
            left_sum += num

        return -1


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [2, 3, -1, 8, 4]
    print(solution.findMiddleIndex(nums1))  # Output: 3

    # test cases 2
    nums2 = [1, -1, 4]
    print(solution.findMiddleIndex(nums2))  # Output: 2

    # test cases 3
    nums3 = [2, 5]
    print(solution.findMiddleIndex(nums3))  # Output: -1
    
    