from typing import List, Optional


class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)

        ans1 = []
        ans2 = []

        for num in set1:
            if num not in set2:
                ans1.append(num)

        for num in set2:
            if num not in set1:
                ans2.append(num)

        return [ans1, ans2]


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,2,3]
    nums2 = [2,4,6]
    result = solution.findDifference(nums1, nums2)
    print(result)

    # test cases 2
    nums3 = [1,2,3,3]
    nums4 = [1,1,2,2]
    result = solution.findDifference(nums3, nums4)
    print(result)
    
    