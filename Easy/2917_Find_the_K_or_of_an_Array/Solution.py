from typing import List, Optional


class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        ans = 0

        for bit in range(32):
            count = 0

            for num in nums:
                if (num >> bit) & 1:
                    count += 1

            if count >= k:
                ans |= (1 << bit)

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [7, 12, 9, 8, 9, 15]
    k1 = 4
    print(solution.findKOr(nums1, k1))  # Output: 9
    
    # test cases 2
    nums2 = [2, 12, 1, 11, 4, 5]
    k2 = 6
    print(solution.findKOr(nums2, k2))  # Output: 0

    # test cases 3
    nums3 = [10, 8, 5, 9, 11, 6, 8]
    k3 = 1
    print(solution.findKOr(nums3, k3))  # Output: 15
    
    