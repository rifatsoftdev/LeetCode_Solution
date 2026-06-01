from typing import List, Optional


class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1:
            return True

        count = 0
        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:
                count += 1
                if count > 1:
                    return False

        return True


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.check([3, 4, 5, 1, 2]))  # Output: True

    # test cases 2
    print(solution.check([2, 1, 3, 4]))  # Output: False

    # test cases 3
    print(solution.check([1, 2, 3]))  # Output: True
    
    
    