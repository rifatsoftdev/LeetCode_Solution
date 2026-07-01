from typing import List, Optional


class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        column = ord(coordinates[0]) - ord('a') + 1
        row = int(coordinates[1])

        return (column + row) % 2 != 0

    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        return self.squareIsWhite(coordinate1) == self.squareIsWhite(coordinate2)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.checkTwoChessboards("a1", "c3"))  # Expected: True
    
    # test cases 2
    print(solution.checkTwoChessboards("a1", "h3"))  # Expected: False
    
    