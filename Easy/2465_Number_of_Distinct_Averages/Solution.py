from typing import List, Optional


class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        nums.sort()
        averages = set()
        
        left, right = 0, len(nums) - 1
        while left < right:
            avg = (nums[left] + nums[right]) / 2
            averages.add(avg)
            left += 1
            right -= 1
            
        return len(averages)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [4, 1, 4, 0, 3, 5]
    print(solution.distinctAverages(nums1))  # Expected: 2
    
    # test cases 2
    nums2 = [1, 100]
    print(solution.distinctAverages(nums2))  # Expected: 1
    
    
    