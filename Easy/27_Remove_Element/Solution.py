from typing import List, Optional


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        ans = 0

        for i in range(len(nums)):
            if nums[i] != val:
                nums[ans] = nums[i]
                ans += 1

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [3, 2, 2, 3]
    val1 = 3
    print(solution.removeElement(nums1, val1))  # Output: 2

    # test cases 2
    nums2 = [0, 1, 2, 2, 3, 0, 4, 2]
    val2 = 2
    print(solution.removeElement(nums2, val2))  # Output: 5