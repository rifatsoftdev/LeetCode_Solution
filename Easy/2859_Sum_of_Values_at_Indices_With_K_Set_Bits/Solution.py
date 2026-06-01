from typing import List, Optional


class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        ans = 0

        for i in range(len(nums)):
            if (bin(i).count("1") == k):
                ans += nums[i]
        
        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [5, 10, 1, 5, 2]
    k1 = 1
    print(solution.sumIndicesWithKSetBits(nums1, k1))  # Expected output: 13
    
    # test cases 2
    nums2 = [4, 3, 2, 1]
    k2 = 2
    print(solution.sumIndicesWithKSetBits(nums2, k2))  # Expected output: 1
    
    
    