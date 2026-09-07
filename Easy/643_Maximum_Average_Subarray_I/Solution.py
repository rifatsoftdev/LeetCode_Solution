from typing import List, Optional


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        max_sum = sum(nums[:k])
        current_sum = max_sum

        for i in range(k, n):
            current_sum += nums[i] - nums[i - k]
            max_sum = max(max_sum, current_sum)

        return max_sum / k


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 12, -5, -6, 50, 3]
    k1 = 4
    print(solution.findMaxAverage(nums1, k1))

    # test cases 2
    nums2 = [5]
    k2 = 1
    print(solution.findMaxAverage(nums2, k2))
    
    