from typing import List, Optional


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        sum = 0;

        for i in range(len(nums)):
            sum += nums[i];

        return sum % k;


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [3, 9, 7]
    k1 = 5
    print(solution.minOperations(nums1, k1))

    # test cases 2
    nums2 = [4, 1, 3]
    k2 = 4
    print(solution.minOperations(nums2, k2))

    # test cases 3
    nums3 = [3, 2]
    k3 = 6
    print(solution.minOperations(nums3, k3))
    
    