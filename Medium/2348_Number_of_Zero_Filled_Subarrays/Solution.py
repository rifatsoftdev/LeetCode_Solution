from typing import List, Optional


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        count = 0
        result = 0

        for num in nums:
            if num == 0:
                count += 1
            else:
                count = 0

            result += count

        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,3,0,0,2,0,0,4]
    print(solution.zeroFilledSubarray(nums1))  # Output: 6

    # test cases 2
    nums2 = [0,0,0,2,0,0]
    print(solution.zeroFilledSubarray(nums2))  # Output: 10

    # test cases 3
    nums3 = [2,10,2019]
    print(solution.zeroFilledSubarray(nums3))  # Output: 0
    