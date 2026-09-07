from typing import List, Optional


class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        freq = {}
        left = 0
        ans = 0

        for right in range(len(nums)):
            freq[nums[right]] = freq.get(nums[right], 0) + 1

            while (freq[nums[right]] > k):
                freq[nums[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,2,3,1,2,3,1,2]
    k1 = 2
    print(solution.maxSubarrayLength(nums1, k1))  # Output: 6

    # test cases 2
    nums2 = [1,2,1,2,1,2,1,2]
    k2 = 1
    print(solution.maxSubarrayLength(nums2, k2))  # Output: 2

    # test cases 3
    nums3 = [5,5,5,5,5,5,5]
    k3 = 4
    print(solution.maxSubarrayLength(nums3, k3))  # Output: 4
    