from typing import List, Optional


class Solution:
    def isVowel(self, ch: str) -> bool:
        return ch in 'aeiouAEIOU'
    
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)
        count = 0

        for i in range(n // 2):
            if self.isVowel(s[i]):
                count += 1
        
        for i in range(n // 2, n):
            if self.isVowel(s[i]):
                count -= 1
        
        return count == 0
            


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.halvesAreAlike("book")) # true

    # test cases 2
    print(solution.halvesAreAlike("textbook")) # false
    