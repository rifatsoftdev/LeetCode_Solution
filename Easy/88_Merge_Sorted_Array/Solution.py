from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        idx = m + n - 1
        i = m - 1
        j = n - 1

        while i >= 0 and j >= 0:
            if nums1[i] >= nums2[j]:
                nums1[idx] = nums1[i]
                idx -= 1
                i -= 1
            else:
                nums1[idx] = nums2[j]
                idx -= 1
                j -= 1

        while j >= 0:
            nums1[idx] = nums2[j]
            idx -= 1
            j -= 1

        while i >= 0:
            nums1[idx] = nums1[i]
            idx -= 1
            i -= 1


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 2, 3, 0, 0, 0]
    m1 = 3
    nums2 = [2, 5, 6]
    n1 = 3
    solution.merge(nums1, m1, nums2, n1)
    print(nums1)  # Output: [1, 2, 2, 3, 5, 6]
    
    # test cases 2
    nums1 = [1]
    m2 = 1
    nums2 = []
    n2 = 0
    solution.merge(nums1, m2, nums2, n2)
    print(nums1)  # Output: [1]

    # test cases 3
    nums1 = [0]
    m3 = 0
    nums2 = [1]
    n3 = 1
    solution.merge(nums1, m3, nums2, n3)
    print(nums1)  # Output: [1]
    
    