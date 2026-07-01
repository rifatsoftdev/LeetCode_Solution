from typing import List, Optional


class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        column = ord(coordinates[0]) - ord('a') + 1
        row = int(coordinates[1])

        return (column + row) % 2 != 0
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.squareIsWhite("a1"))  # Expected: False
    
    # test cases 2
    print(solution.squareIsWhite("h3"))  # Expected: True
    
    # test cases 3
    print(solution.squareIsWhite("c7"))  # Expected: False
    
    