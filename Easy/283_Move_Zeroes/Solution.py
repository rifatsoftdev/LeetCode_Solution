from typing import List, Optional


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n: int = len(nums)
        start: int = 0

        for i in range(n):
            if (nums[i] != 0):
                nums[start], nums[i] = nums[i], nums[start]
                start += 1
          

if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [0,1,0,3,12]
    solution.moveZeroes(nums1)
    print(nums1)

    # test cases 2
    nums2 = [0]
    solution.moveZeroes(nums2)
    print(nums2)
    