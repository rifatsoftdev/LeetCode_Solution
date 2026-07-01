from typing import List, Optional


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums_sum = sum(nums)
        total_sum = int(n * (n + 1) / 2)

        return total_sum - nums_sum


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [3, 0, 1]
    print(solution.missingNumber(nums1))

    # test cases 2
    nums2 = [0, 1]
    print(solution.missingNumber(nums2))

    # test cases 3
    nums3 = [9, 6, 4, 2, 3, 5, 7, 0, 1]
    print(solution.missingNumber(nums3))
    