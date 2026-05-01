from typing import Optional, List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}

        for i in range(len(nums)):
            complement = target - nums[i]

            if (seen.get(complement) != None):
                return [seen[complement], i]
            
            seen[nums[i]] = i
        
        return []


if __name__ == "__main__":
    solution = Solution()

    #  test cases 1
    nums1 = [2,7,11,15]
    print(solution.twoSum(nums1, 9))

    # test cases 2
    nums2 = [3,2,4]
    print(solution.twoSum(nums2, 6))

    # test cases 3
    nums3 = [3,3]
    print(solution.twoSum(nums3, 6))