from typing import List, Optional


class Solution:
    def processStr(self, s: str) -> str:
        result = []

        for c in s:
            if c == '*':
                # Remove the last character
                if result:
                    result.pop()
            elif c == '#':
                # Duplicate
                if result:
                    result.extend(result[:])
            elif c == '%':
                # Reverse
                result.reverse()
            else:
                # Append
                result.append(c)

        return "".join(result)
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "a#b%*"
    print(solution.processStr(s1))

    # test cases 2
    s2 = "z*#"
    print(solution.processStr(s2))
    
   