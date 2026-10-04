from typing import List, Optional


class Solution:
    def sumFoDigit(self, n):
        ans = 0

        while (n != 0):
            d = n % 10
            ans += d
            n //= 10

        return ans

    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if (i == self.sumFoDigit(nums[i])):
                return i
           
        return -1


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1,3,2];
    print(solution.smallestIndex(nums1));

    # test cases 2
    nums2 = [1,10,11];
    print(solution.smallestIndex(nums2));

    # test cases 3
    nums3 = [1,2,3];
    print(solution.smallestIndex(nums3));
    
    