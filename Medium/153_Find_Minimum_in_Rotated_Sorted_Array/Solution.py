from typing import List, Optional


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while (left < right):
            mid = left + (right - left) // 2

            if (nums[mid] > nums[right]):
                left = mid + 1
            else:
                right = mid
        
        return nums[left]


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [3,4,5,1,2]
    print(solution.findMin(nums1))

    # test cases 2
    nums2 = [4,5,6,7,0,1,2]
    print(solution.findMin(nums2))

    # test cases 3
    nums3 = [11,13,15,17]
    print(solution.findMin(nums3))
    