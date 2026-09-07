from typing import List, Optional


class Solution:
    def findDegrees(self, matrix: list[list[int]]) -> list[int]:
        result = []

        for i in range(len(matrix)):
            tmp = 0

            for j in range(len(matrix[i])):
                tmp += matrix[i][j]

            result.append(tmp)

        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    matrix1 = [[0,1,1],[1,0,1],[1,1,0]];
    result1 = solution.findDegrees(matrix1);
    print(result1);

    # test cases 2
    matrix2 = [[0,1,0],[1,0,0],[0,0,0]];
    result2 = solution.findDegrees(matrix2);
    print(result2);

    # test cases 3
    matrix3 = [[0]];
    result3 = solution.findDegrees(matrix3);
    print(result3);
    