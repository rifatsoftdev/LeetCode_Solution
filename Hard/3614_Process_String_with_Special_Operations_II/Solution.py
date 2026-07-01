from typing import List, Optional


class Solution:
    def processStr(self, s: str, k: int) -> str:
        m = 0

        # Final length
        for c in s:
            if c == '*':
                if m > 0:
                    m -= 1
            elif c == '#':
                m *= 2
            elif c != '%':
                m += 1

        if k >= m:
            return '.'

        # Reverse simulation
        for c in reversed(s):
            if c == '*':
                m += 1

            elif c == '#':
                m //= 2
                if k >= m:
                    k -= m

            elif c == '%':
                k = m - 1 - k

            else:  # letter
                m -= 1
                if k == m:
                    return c

        return '.'


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "a#b%*"
    k1 = 1
    print(solution.processStr(s1, k1))
    
    # test cases 2
    s2 = "cd%#*#"
    k2 = 3
    print(solution.processStr(s2, k2))

    # test cases 3
    s3 = "z*#"
    k3 = 0
    print(solution.processStr(s3, k3))
    
    
    