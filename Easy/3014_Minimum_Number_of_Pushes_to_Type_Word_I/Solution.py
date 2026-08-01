from typing import List, Optional


class Solution:
    def minimumPushes(self, word: str) -> int:
        ans = 0

        for i in range(len(word)):
            ans += i // 8 + 1

        return ans
        

if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    word1 = "abcde"
    print(solution.minimumPushes(word1))

    # test cases 2
    word2 = "xycdefghij"
    print(solution.minimumPushes(word2))
    