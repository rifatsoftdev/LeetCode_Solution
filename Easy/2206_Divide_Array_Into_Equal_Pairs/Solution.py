from typing import List, Optional


class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        feq = {}

        for n in nums:
            if (n in feq):
                feq[n] += 1
            else:
                feq[n] = 1

        for key, val in feq.items():
            if (val % 2 != 0):
                return False

        return True


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [3,2,3,2,2,2]
    print(solution.divideArray(nums1))

    # test cases 2
    nums2 = [1,2,3,4]
    print(solution.divideArray(nums2))
    