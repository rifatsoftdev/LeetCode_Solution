from typing import List, Optional


class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        missing = []
        countMap = {}
        minNum = float('inf')
        maxNum = float('-inf')

        for num in nums:
            countMap[num] = countMap.get(num, 0) + 1
            minNum = min(minNum, num)
            maxNum = max(maxNum, num)

        for num in range(minNum, maxNum + 1):
            if num not in countMap:
                missing.append(num)

        return missing


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,4,2,5]
    missing1 = solution.findMissingElements(nums1)
    print(missing1)  # Expected output: [3]

    # test cases 2
    nums2 = [7,8,6,9]
    missing2 = solution.findMissingElements(nums2)
    print(missing2)  # Expected output: []

    # test cases 3
    nums3 = [5,1]
    missing3 = solution.findMissingElements(nums3)
    print(missing3)  # Expected output: [2,3,4]
    
    