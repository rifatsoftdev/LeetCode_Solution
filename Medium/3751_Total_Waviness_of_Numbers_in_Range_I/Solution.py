from typing import List, Optional


class Solution:
    def waviness(self, x) -> int:
        s = str(x)

        if (len(s) < 3):
            return 0

        cnt = 0

        for i in range(1, len(s)-1):
            if ((s[i] > s[i-1] and s[i] > s[i+1]) or (s[i] < s[i-1] and s[i] < s[i+1])):
                cnt += 1

        return cnt

    def totalWaviness(self, num1: int, num2: int) -> int:
        cnt = 0

        for i in range(num1, num2+1):
            cnt += self.waviness(i)

        return cnt


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.totalWaviness(120, 130))

    # test cases 2
    print(solution.totalWaviness(198, 202))

    # test cases 3
    print(solution.totalWaviness(4848, 4848))
    