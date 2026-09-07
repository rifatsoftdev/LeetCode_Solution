from typing import List, Optional


class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        current = n
        temp = current

        while True:
            product = 1
            temp = current

            while temp > 0:
                digit = temp % 10
                product *= digit
                temp //= 10

            if product % t == 0:
                return current

            current += 1


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.smallestNumber(10, 2))  # Expected output: 10

    # test cases 2
    print(solution.smallestNumber(15, 3))  # Expected output: 16
    