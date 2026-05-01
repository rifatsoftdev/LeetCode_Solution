


class Solution:
    def mySqrt(self, x: int) -> int:
        if (x == 0 or x == 1):
            return x
        
        left = 0
        right = x // 2
        ans = 0

        while (left <= right):
            mid = (left + right) // 2

            if (mid * mid == x):
                return mid
            elif (mid * mid < x):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        
        return ans


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.mySqrt(4))

    # test cases 2
    print(solution.mySqrt(8))