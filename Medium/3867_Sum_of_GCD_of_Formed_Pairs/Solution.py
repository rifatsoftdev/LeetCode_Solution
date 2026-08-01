from typing import List, Optional


class Solution:
    def gcd(self, a: int, b: int) -> int:
        while b:
            a, b = b, a % b
        return a

    def gcdSum(self, nums: list[int]) -> int:
        prefix = []
        mx = 0

        for x in nums:
            mx = max(mx, x)
            prefix.append(self.gcd(x, mx))

        prefix.sort()

        ans = 0
        l, r = 0, len(prefix) - 1

        while l < r:
            ans += self.gcd(prefix[l], prefix[r])
            l += 1
            r -= 1

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [2,6,4]
    print(solution.gcdSum(nums1))

    # test cases 2
    nums2 = [3,6,2,8]
    print(solution.gcdSum(nums2))