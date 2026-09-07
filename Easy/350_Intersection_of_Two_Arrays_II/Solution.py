from typing import List, Optional


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()

        i, j = 0, 0
        result = []

        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]
    result1 = solution.intersect(nums1, nums2)
    print(result1)  # Expected output: [2, 2]

    # test cases 2
    nums3 = [4, 9, 5]
    nums4 = [9, 4, 9, 8, 4]
    result2 = solution.intersect(nums3, nums4)
    print(result2)  # Expected output: [4, 9]
    
    