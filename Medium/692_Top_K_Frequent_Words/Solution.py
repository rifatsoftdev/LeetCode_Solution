from typing import List, Optional


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]

        return nums


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,2,3,4]
    result1 = solution.runningSum(nums1)
    print(result1)  # Output: [1,3,6,10]

    # test cases 2
    nums2 = [1,1,1,1]
    result2 = solution.runningSum(nums2)
    print(result2)  # Output: [1,2,3,4]
    
    