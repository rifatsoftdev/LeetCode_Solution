from typing import List, Optional


class Solution:
    def sumZero(self, n: int) -> List[int]:
        result = []

        if n % 2 == 1:
            result.append(0)

        for i in range(1, n // 2 + 1):
            result.append(i)
            result.append(-i)
        
        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    n1 = 5
    print(solution.sumZero(n1))  # Output: [-2, -1, 0, 1, 2]

    # test cases 2
    n2 = 3
    print(solution.sumZero(n2))  # Output: [-1, 0, 1]

    # test cases 3
    n3 = 1
    print(solution.sumZero(n3))  # Output: [0]
    