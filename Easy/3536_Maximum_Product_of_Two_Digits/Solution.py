from typing import List, Optional


class Solution:
    def maxProduct(self, n: int) -> int:
        firstLarge = 0
        secondLarge = 0

        while (n != 0):
            digit = n % 10

            if (digit > firstLarge):
                secondLarge = firstLarge
                firstLarge = digit
    
            elif (digit > secondLarge):
                secondLarge = digit
            
            n //= 10

        return firstLarge * secondLarge


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    n1 = 31
    print(solution.maxProduct(n1))

    # test cases 2
    n2 = 22
    print(solution.maxProduct(n2))

    # test cases 3
    n3 = 124
    print(solution.maxProduct(n3))
    
    