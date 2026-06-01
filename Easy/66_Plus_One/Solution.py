from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s = ''.join(map(str, digits))
        s = str(int(s) + 1)
        return [int(i) for i in s]


if __name__ == "__main__":
    solution = Solution()

    # test saces 1
    digits = [1, 2, 3]
    print(solution.plusOne(digits))

    # test saces 2
    digits = [4, 3, 2, 1]
    print(solution.plusOne(digits))

    # test saces 3
    digits = [9]
    print(solution.plusOne(digits))
    