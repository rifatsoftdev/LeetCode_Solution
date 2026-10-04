from typing import List, Optional


class Solution:
    def concatWithReverse(self, nums: list[int]) -> list[int]:
        result = nums.copy()
        result.extend(reversed(nums))

        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 2, 3]
    result1 = solution.concatWithReverse(nums1)
    print(result1)

    # test cases 2
    nums2 = [1]
    result2 = solution.concatWithReverse(nums2)
    print(result2)
    