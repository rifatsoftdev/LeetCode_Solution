from typing import List, Optional


class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        nums.sort()
        n = len(nums)
        averages = []
        
        for i in range(n // 2):
            min_val = nums[i]
            max_val = nums[n - 1 - i]
            averages.append((min_val + max_val) / 2)
            
        return min(averages)
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [7, 8, 3, 4, 15, 13, 4, 1]
    print(solution.minimumAverage(nums1))  # Expected: 5.5
    
    # test cases 2
    nums2 = [1, 9, 8, 3, 10, 5]
    print(solution.minimumAverage(nums2))  # Expected: 5.5

    # test cases 3
    nums3 = [1, 2, 3, 7, 8, 9]
    print(solution.minimumAverage(nums3))  # Expected: 5.0
    
    
    