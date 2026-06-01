from typing import List, Optional


class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        ans = len(nums)

        for i in range(len(nums)):
            if (nums[i] == target):
                ans = min(ans, abs(i - start))
        
        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums = [1,2,3,4,5]
    target = 5
    start = 3
    print(solution.getMinDistance(nums, target, start))

    # test cases 2
    nums = [1]
    target = 1
    start = 0
    print(solution.getMinDistance(nums, target, start))

    # test cases 3
    nums = [1,1,1,1,1,1,1,1,1,1]
    target = 1
    start = 0
    print(solution.getMinDistance(nums, target, start))
    