from typing import List, Optional



class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(2, n):
            half = nums[i-1] / 2.0
            sum_ = nums[i-2] + nums[i]

            if sum_ == half:
                ans += 1

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.countSubarrays([1,2,1,4,1]))  # Output: 1
    
    # test cases 2
    print(solution.countSubarrays([1,1,1]))  # Output: 1
    