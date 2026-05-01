from typing import List


# class Solution:
#     def maxRotateFunction(self, nums: List[int]) -> int:
#         n = len(nums)
#         nums = nums + nums
#         maxNum = float('-inf')

#         for i in range(n):
#             j = i
#             m = 0
#             total = 0

#             while j < i + n:
#                 total += nums[j] * m
#                 m += 1
#                 j += 1
            
#             maxNum = max(maxNum, total)
        
#         return maxNum


class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        totalSum = sum(nums)

        F = sum(i * nums[i] for i in range(n))
        maxVal = F

        for k in range(1, n):
            F = F + totalSum - n * nums[n - k]
            maxVal = max(maxVal, F)

        return maxVal


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [4, 3, 2, 6]
    print(solution.maxRotateFunction(nums1))

    # test cases 2
    nums2 = [100]
    print(solution.maxRotateFunction(nums2))

    # test cases 1
    # nums3 = [-4, -3, -2, -6]
    # print(solution.maxRotateFunction(nums3))

