from typing import Optional, List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while (left <= right):
            mid = (left + right) // 2

            if (nums[mid] == target):
                return mid
            
            if (nums[mid] >= nums[left]):
                if (nums[left] <= target < nums[mid]):
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if (nums[mid] < target <= nums[right]):
                    left = mid + 1
                else:
                    right = mid - 1
        
        return -1



if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [4,5,6,7,0,1,2]
    target1 = 0
    print(solution.search(nums1, target1))

    # test cases 2
    nums1 = [4,5,6,7,0,1,2]
    target1 = 3
    print(solution.search(nums1, target1))

    # test cases 3
    nums1 = [1]
    target1 = 0
    print(solution.search(nums1, target1))