from typing import List, Optional


class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n

        for i in range(n):
            ans[i] = nums[nums[i]]

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [0,2,1,5,3,4]
    result1 = solution.buildArray(nums1)
    print(result1)

    # test cases 2
    nums2 = [5,0,1,2,3,4]
    result2 = solution.buildArray(nums2)
    print(result2)
    