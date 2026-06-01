from typing import List, Optional


class Solution:
    def getPermute(self, nums: list, idx: int, ans: list):
        if (idx == len(nums)):
            ans.append(nums[:])
            return
        
        for i in range(idx, len(nums)):
            nums[idx], nums[i] = nums[i], nums[idx]
            self.getPermute(nums, idx+1, ans)
            nums[idx], nums[i] = nums[i], nums[idx]

    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.getPermute(nums, 0, ans)
        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.permute([1, 2, 3]))

    # test cases 2
    print(solution.permute([0,1]))

    # test cases 3
    print(solution.permute([1]))
