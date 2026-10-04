from typing import List, Optional


class Solution:
    def repeatedCharacter(self, s: str) -> str:
        seen = set()

        for char in s:
            if char in seen:
                return char
            seen.add(char)

        return ""


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "abccbaacz"
    print(solution.repeatedCharacter(s1))

    # test cases 2
    s2 = "abcdd"
    print(solution.repeatedCharacter(s2))
    