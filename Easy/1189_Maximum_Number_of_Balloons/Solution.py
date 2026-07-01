from typing import List, Optional


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq = {}

        for c in text:
            freq[c] = freq.get(c, 0) + 1

        return min(
            freq.get('b', 0),
            freq.get('a', 0),
            freq.get('l', 0) // 2,
            freq.get('o', 0) // 2,
            freq.get('n', 0)
        )


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    text1 = "nlaebolko"
    print(solution.maxNumberOfBalloons(text1))

    # test cases 2
    text2 = "loonbalxballpoon"
    print(solution.maxNumberOfBalloons(text2))

    # test cases 3
    text3 = "leetcode"
    print(solution.maxNumberOfBalloons(text3))
    
    