from typing import List, Optional


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        fast = 0
        last = n - 1
        idx = n - 1
        result = [0] * n

        while (fast <= last):
            fast_sq = nums[fast] * nums[fast]
            last_sq = nums[last] * nums[last]

            if (fast_sq < last_sq):
                result[idx] = last_sq
                last -= 1
            else:
                result[idx] = fast_sq
                fast += 1
            idx -= 1
        
        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums = [-4, -1, 0, 3, 10]
    print(solution.sortedSquares(nums))

    # test cases 2
    nums = [-7, -3, 2, 3, 11]
    print(solution.sortedSquares(nums))
    
    
    