from typing import List, Optional


class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        return nums * 2


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 2, 1]
    print(solution.getConcatenation(nums1))
    
    # test cases 2
    nums2 = [1, 3, 2, 1]
    print(solution.getConcatenation(nums2))
    
    