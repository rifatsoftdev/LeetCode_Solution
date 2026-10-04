from typing import List, Optional


class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            pos = s.find(part)
            s = s[:pos] + s[pos + len(part):]

        return s

    # def removeOccurrences(self, s: str, part: str) -> str:
    #     while part in s:
    #         s = s.replace(part, "", 1)

    #     return s


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "daabcbaabcbc"
    part1 = "abc"
    print(solution.removeOccurrences(s1, part1))

    # test cases 2
    s2 = "axxxxyyyyb"
    part2 = "xy"
    print(solution.removeOccurrences(s2, part2))
    
    