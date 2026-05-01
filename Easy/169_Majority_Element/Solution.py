from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        count = {}

        for num in nums:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1

        for num, freq in count.items():
            if freq > n // 2:
                return num
            
        return -1


if __name__ == "__main__":
    solution = Solution()
    
    print(solution.majorityElement([3, 2, 3]))  # Output: 3
    print(solution.majorityElement([2, 2, 1, 1, 1, 2, 2]))  # Output: 2