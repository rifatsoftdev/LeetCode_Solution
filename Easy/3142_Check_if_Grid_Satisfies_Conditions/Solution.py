from typing import List, Optional


class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        m = len(grid[0]) if n > 0 else 0

        for i in range(n):
            for j in range(m):
                if (j + 1 < m and grid[i][j] == grid[i][j + 1]):
                    return False
                if (i + 1 < n and grid[i][j] != grid[i + 1][j]):
                    return False
        
        return True


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    grid1 = [[1, 0, 2], [1, 0, 2]]
    print(solution.satisfiesConditions(grid1))  # Output: true

    # test cases 2
    grid2 = [[1, 1, 1], [0, 0, 0]]
    print(solution.satisfiesConditions(grid2))  # Output: false

    # test cases 3
    grid3 = [[1], [2], [3]]
    print(solution.satisfiesConditions(grid3))  # Output: false
    
    