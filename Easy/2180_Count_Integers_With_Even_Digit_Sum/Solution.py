

class Solution:
    def sumOfDrgit(self, n):
        ans = 0
        while n > 0:
            ans += n % 10
            n //= 10
        return ans
    
    def countEven(self, num: int) -> int:
        ans = 0

        for i in range(1, num + 1):
            if self.sumOfDrgit(i) % 2 == 0:
                ans += 1

        return ans


if __name__ == "__main__":
    solution = Solution()
    
    # test cases 1
    print(solution.countEven(4))

    # test cases 2
    print(solution.countEven(30))
        
        