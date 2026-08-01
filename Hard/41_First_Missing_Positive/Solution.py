from typing import List, Optional


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        target = 1

        for num in nums:
            if num == target:
                target += 1
            elif num > target:
                break

        return target


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,2,0]
    print(solution.firstMissingPositive(nums1))
    
    # test cases 2
    nums2 = [3,4,-1,1]
    print(solution.firstMissingPositive(nums2))
    
    # test cases 3
    nums3 = [7,8,9,11,12]
    print(solution.firstMissingPositive(nums3))