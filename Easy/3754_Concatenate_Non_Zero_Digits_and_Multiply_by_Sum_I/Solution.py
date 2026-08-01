from typing import List, Optional


class Solution:
    def sumAndMultiply(self, n: int) -> int:
        digits = str(n)

        concatenated_digits = ""
        digit_sum = 0

        for digit in digits:
            if digit != '0':
                concatenated_digits += digit
                digit_sum += int(digit)

        concatenated_number = int(concatenated_digits) if concatenated_digits else 0

        return concatenated_number * digit_sum


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.sumAndMultiply(10203004))  # Output: 12340

    # test cases 2
    print(solution.sumAndMultiply(1000))  # Output: 0