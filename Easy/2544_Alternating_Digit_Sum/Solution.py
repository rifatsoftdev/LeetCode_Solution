

class Solution:
    def alternateDigitSum(self, n: int) -> int:
        digits = [int(d) for d in str(n)]
        ans = 0
        cnt = 0

        for i in digits:
            if (cnt % 2 == 0):
                ans += i
            else:
                ans -= i
            cnt += 1
        
        return ans


if __name__ == "__main__":
    solution = Solution()
    
    # test cases 1
    print(solution.alternateDigitSum(521))

    # test cases 2
    print(solution.alternateDigitSum(111))

    # test cases 3
    print(solution.alternateDigitSum(886996))
        