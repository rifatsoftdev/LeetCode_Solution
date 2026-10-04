from typing import List, Optional


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        map = {}
        count = 0

        for i in range(len(nums)):
            if nums[i] in map:
                count += map[nums[i]]
                map[nums[i]] += 1
            else:
                map[nums[i]] = 1

        return count


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 2, 3, 1, 1, 3]
    result1 = solution.numIdenticalPairs(nums1)
    print(result1)

    # test cases 2
    nums2 = [1, 1, 1, 1]
    result2 = solution.numIdenticalPairs(nums2)
    print(result2)

    # test cases 3
    nums3 = [1, 2, 3]
    result3 = solution.numIdenticalPairs(nums3)
    print(result3)