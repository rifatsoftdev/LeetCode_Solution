from typing import List, Optional


class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = max(nums)

        if (len(nums) != n+1):
            return False
        
        expected = list(range(1, n+1))
        expected.append(n)

        return sorted(nums) == expected


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [2, 1, 3]
    print(solution.isGood(nums1))

    # test cases 2
    nums2 = [1, 3, 3, 2]
    print(solution.isGood(nums2))

    # test cases 3
    nums3 = [1, 1]
    print(solution.isGood(nums3))

    # test cases 4
    nums4 = [3, 4, 4, 1, 2, 1]
    print(solution.isGood(nums4))
    