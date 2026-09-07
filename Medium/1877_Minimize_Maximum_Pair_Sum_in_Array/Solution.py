from typing import List, Optional


class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        max_pair_sum = 0
        n = len(nums)

        for i in range(n // 2):
            pair_sum = nums[i] + nums[n - 1 - i]
            max_pair_sum = max(max_pair_sum, pair_sum)

        return max_pair_sum

if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [3, 5, 2, 3]
    print(solution.minPairSum(nums1))  # Output: 7

    # test cases 2
    nums2 = [3, 5, 4, 2, 4, 6]
    print(solution.minPairSum(nums2))  # Output: 8
    