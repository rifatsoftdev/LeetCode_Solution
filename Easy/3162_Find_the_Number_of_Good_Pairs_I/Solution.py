from typing import List, Optional


class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        count = 0

        for n1 in nums1:
            for n2 in nums2:
                if n1 % (n2 * k) == 0:
                    count += 1
        
        return count
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 3, 4]
    nums2 = [1, 3, 4]
    k = 1
    print(solution.numberOfPairs(nums1, nums2, k))  # Output: 5
    
    # test cases 2
    nums1 = [1, 2, 4, 12]
    nums2 = [2, 4]
    k = 3
    print(solution.numberOfPairs(nums1, nums2, k))  # Output: 2
    
    