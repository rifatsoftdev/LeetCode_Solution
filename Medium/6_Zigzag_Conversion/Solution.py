from typing import List, Optional


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [''] * numRows
        current_row = 0
        going_down = False

        for char in s:
            rows[current_row] += char

            if current_row == 0 or current_row == numRows - 1:
                going_down = not going_down

            current_row += 1 if going_down else -1

        return ''.join(rows)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "PAYPALISHIRING";
    numRows1 = 3;
    print(solution.convert(s1, numRows1))  # Output: "PAHNAPLSIIGYIR"
    
    # test cases 2
    s2 = "PAYPALISHIRING";
    numRows2 = 4;
    print(solution.convert(s2, numRows2))  # Output: "PINALSIGYAHRPI"

    # test cases 3
    s3 = "A";
    numRows3 = 1;
    print(solution.convert(s3, numRows3))  # Output: "A"