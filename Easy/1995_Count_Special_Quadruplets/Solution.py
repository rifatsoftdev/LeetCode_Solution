from typing import List, Optional


class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    for l in range(k + 1, n):
                        if nums[i] + nums[j] + nums[k] == nums[l]:
                            count += 1

        return count


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,2,3,6]
    print(solution.countQuadruplets(nums1)); # Output: 1

    # test cases 2
    nums2 = [3,3,6,4,5]
    print(solution.countQuadruplets(nums2)); # Output: 0

    # test cases 3
    nums3 = [1,1,1,3,5]
    print(solution.countQuadruplets(nums3)); # Output: 4

    
    