from typing import List, Optional


class Solution:
    def search(self, nums: list[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while (left <= right):
            mid = left + (right - left) // 2

            if (nums[mid] == target):
                return mid
            elif (nums[mid] < target):
                left = mid + 1
            else:
                right = mid - 1
           
        return -1


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [-1, 0, 3, 5, 9, 12]
    target1 = 9
    print(solution.search(nums1, target1))  # Output: 4

    # test cases 2
    nums2 = [1, -1, 4]
    target2 = 2
    print(solution.search(nums2, target2))  # Output: -1

   