from typing import List, Optional


class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        smaller = []
        equal = []
        greater = []

        for num in nums:
            if num < pivot:
                smaller.append(num)
            elif num == pivot:
                equal.append(num)
            else:
                greater.append(num)

        return smaller + equal + greater


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [9, 12, 5, 10, 14, 3, 10]
    pivot1 = 10
    print(solution.pivotArray(nums1, pivot1))  # Output: [9, 5, 3, 10, 10, 12, 14]

    # test cases 2
    nums2 = [-3, 4, 3, 2]
    pivot2 = 2
    print(solution.pivotArray(nums2, pivot2))  # Output: [-3, 2, 4, 3]