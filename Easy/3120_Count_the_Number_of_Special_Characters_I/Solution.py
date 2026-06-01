from typing import List, Optional


class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        s = set(word)
        count = 0

        for i in s:
            if (i.isupper() and i.lower() in s):
                count += 1
        
        return count


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.numberOfSpecialChars("aaAbcBC"))

    # test cases 2
    print(solution.numberOfSpecialChars("abc"))

    # test cases 3
    print(solution.numberOfSpecialChars("abBCab"))
    
    