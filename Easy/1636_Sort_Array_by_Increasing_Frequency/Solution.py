from typing import List, Optional
from collections import Counter


class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq = Counter(nums)

        nums.sort(key=lambda x: (freq[x], -x))

        return nums


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    # test cases 2
    
    