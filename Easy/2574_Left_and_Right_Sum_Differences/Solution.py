from typing import List, Optional


class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left_sum = [0] * n
        right_sum = [0] * n
        
        current_left = 0
        for i in range(n):
            left_sum[i] = current_left
            current_left += nums[i]
            
        current_right = 0
        for i in range(n - 1, -1, -1):
            right_sum[i] = current_right
            current_right += nums[i]
            
        return [abs(left_sum[i] - right_sum[i]) for i in range(n)]


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [10, 4, 8, 3]
    print(solution.leftRightDifference(nums1))
    # Expected: [15, 1, 11, 22]

    # test cases 2
    nums2 = [1]
    print(solution.leftRightDifference(nums2))
    # Expected: [0]
    
    
    