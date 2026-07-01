from typing import List, Optional


class Solution:
    def canAliceWin(self, n: int) -> bool:
        Alice = True
        turn = 10

        while (n >= turn):
            n -= turn
            turn -= 1
            Alice = not Alice
        
        return not Alice


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.canAliceWin(12))

    # test cases 2
    print(solution.canAliceWin(1))
    