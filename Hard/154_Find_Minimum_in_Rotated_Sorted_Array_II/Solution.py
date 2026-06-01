from typing import List, Optional


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while (left < right):
            mid = left + (right - left) // 2

            if (nums[mid] > nums[right]):
                left = mid + 1
            elif (nums[mid] < nums[right]):
                right = mid
            else:
                right -= 1
        
        return nums[left]


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,3,5]
    print(solution.findMin(nums1))

    # test cases 2
    nums2 = [2,2,2,0,1]
    print(solution.findMin(nums2))
    