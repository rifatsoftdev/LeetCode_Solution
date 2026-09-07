from typing import List, Optional


class Solution:
    def largestOddNumber(self, num: str) -> str:
        for i in range(len(num) - 1, -1, -1):
            if int(num[i]) % 2 == 1:
                return num[:i + 1]
            
        return ""


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    num1 = "52"
    print(solution.largestOddNumber(num1))  # Output: "5"

    # test cases 2
    num2 = "4206"
    print(solution.largestOddNumber(num2))  # Output: ""

    # test cases 3
    num3 = "35427"
    print(solution.largestOddNumber(num3))  # Output: "35427"
    