from typing import List, Optional


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1 = "".join(sorted(s1))
        n = len(s1)

        for i in range(n, len(s2) + 1):
            s = "".join(sorted(s2[i-n:i]))

            if (s1 == s):
                return True

        return False


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s11 = "ab"
    s21 = "eidbaooo"
    print(solution.checkInclusion(s11, s21))

    # test cases 2
    s12 = "ab"
    s22 = "eidboaoo"
    print(solution.checkInclusion(s12, s22))
