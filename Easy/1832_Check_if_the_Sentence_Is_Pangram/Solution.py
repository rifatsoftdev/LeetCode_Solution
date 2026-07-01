from typing import List, Optional


class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        return len(set(sentence)) == 26


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.checkIfPangram("thequickbrownfoxjumpsoverthelazydog"))

    # test cases 2
    print(solution.checkIfPangram("leetcode"))
    