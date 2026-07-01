from typing import List, Optional


class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)

        for i in range(n-1):
            if (nums[i] == nums[i + 1]):
                nums[i] = nums[i] * 2
                nums[i + 1] = 0

        start = 0

        for i in range(n):
            if (nums[i] != 0):
                nums[start], nums[i] = nums[i], nums[start]
                start += 1

        return nums


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 2, 2, 1, 1, 0]
    print(solution.applyOperations(nums1))
    
    # test cases 2
    nums2 = [0, 1]
    print(solution.applyOperations(nums2))
    
    
    