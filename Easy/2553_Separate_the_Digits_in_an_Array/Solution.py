from typing import List


class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []

        for i in nums:
            digits = [int(d) for d in str(i)]
            ans.extend(digits)

        return ans


if __name__ == "__main__":
    solution = Solution()
    
    # test cases 1
    nums1 = [13,25,83,77]
    ans1 = solution.separateDigits(nums1)
    print(ans1)
        
    # test cases 2
    nums2 = [7,1,3,9]
    ans2 = solution.separateDigits(nums2)
    print(ans2)