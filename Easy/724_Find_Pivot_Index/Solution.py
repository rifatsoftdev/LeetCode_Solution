from typing import List, Optional


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
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
    nums1 = [1, 7, 3, 6, 5, 6]
    print(solution.pivotIndex(nums1))  # Output: 3

    # test cases 2
    nums2 = [1, 2, 3]
    print(solution.pivotIndex(nums2))  # Output: -1

    # test cases 3
    nums3 = [2, 1, -1]
    print(solution.pivotIndex(nums3))  # Output: 0
    