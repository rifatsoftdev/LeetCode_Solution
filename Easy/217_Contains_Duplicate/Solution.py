from typing import List, Optional


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()

        for num in nums:
            if num in seen:
                return True
            seen.add(num)

        return False
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 2, 3, 1]
    print(solution.containsDuplicate(nums1))
    
    # test cases 2
    nums2 = [1, 2, 3, 4]
    print(solution.containsDuplicate(nums2))

    # test cases 3
    nums3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
    print(solution.containsDuplicate(nums3))
    
    