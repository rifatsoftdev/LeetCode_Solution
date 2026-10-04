from typing import List, Optional


class Solution:
    def alternatingSum(self, nums: List[int]) -> int:
        total = 0

        for i in range(len(nums)):
            if i % 2 == 0:
                total += nums[i]
            else:
                total -= nums[i]
        
        return total


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 3, 5, 7]
    print(solution.alternatingSum(nums1))  # Output: -4

    # test cases 2
    nums2 = [100]
    print(solution.alternatingSum(nums2))  # Output: 100
    