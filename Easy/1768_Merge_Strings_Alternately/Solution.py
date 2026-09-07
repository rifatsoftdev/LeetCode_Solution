import string
from typing import List, Optional


class Solution(object):
    def mergeAlternately(self, word1: str, word2: str) -> str:
        m = min(len(word1), len(word2))
        result = []

        for i in range(m):
            result.append(word1[i])
            result.append(word2[i])
        
        result.append(word1[m:])
        result.append(word2[m:])
        
        return ''.join(result)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    word1 = "abc"
    word2 = "pqr"
    result = solution.mergeAlternately(word1, word2)
    print(result) # Expected: "apbqcr"

    # test cases 2
    word1 = "ab"
    word2 = "pqrs"
    result = solution.mergeAlternately(word1, word2);
    print(result) # Expected: "apbqcr"

    # test cases 3
    word1 = "abcd"
    word2 = "pq"
    result = solution.mergeAlternately(word1, word2);
    print(result) # Expected: "apbqcr"

    