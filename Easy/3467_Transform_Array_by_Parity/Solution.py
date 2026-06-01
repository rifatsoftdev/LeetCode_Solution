from typing import List, Optional


class Solution:
    def transformArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1] * n
        zero = 0
        one = n-1

        for i in range(n):
            if (nums[i] % 2 == 0):
                ans[zero] = 0
                zero += 1
            else:
                ans[one] = 1
                one -= 1
        
        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [4, 3, 2, 1]
    print(solution.transformArray(nums1))
    
    # test cases 2
    nums2 = [1, 5, 1, 4, 2]
    print(solution.transformArray(nums2))
    
    
    