from typing import List, Optional


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxNum = 0
        count = 0

        for i in nums:
            if (i == 1):
                count += 1
                maxNum = max(maxNum, count)
            else:
                count = 0

        return maxNum


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 1, 0, 1, 1, 1]
    print(solution.findMaxConsecutiveOnes(nums1))  # Output: 3
    
    # test cases 2
    nums2 = [1, 0, 1, 1, 0, 1]
    print(solution.findMaxConsecutiveOnes(nums2))  # Output: 2
    
    
    
    