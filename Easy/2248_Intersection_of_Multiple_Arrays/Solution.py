from typing import List, Optional


class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        count = [0] * 1001
        n = len(nums)

        for arr in nums:
            unique_elements = set(arr)
            for num in unique_elements:
                count[num] += 1

        result = []

        for i in range(1001):
            if count[i] == n:
                result.append(i)

        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
    result1 = solution.intersection(nums1)
    print(result1)  # Output: [3, 4]

    # test cases 2
    nums2 = [[1,2,3],[4,5,6]]
    result2 = solution.intersection(nums2)
    print(result2)  # Output: []
    