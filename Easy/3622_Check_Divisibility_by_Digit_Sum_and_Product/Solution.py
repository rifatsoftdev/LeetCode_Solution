from typing import List, Optional


class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum = 0;
        pro = 1;
        m = n;

        while (n != 0):
            d = n % 10;

            sum += d;
            pro *= d;

            n //= 10;
        
        return m % (sum + pro) == 0;


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.checkDivisibility(99))

    # test cases 2
    print(solution.checkDivisibility(23))
    