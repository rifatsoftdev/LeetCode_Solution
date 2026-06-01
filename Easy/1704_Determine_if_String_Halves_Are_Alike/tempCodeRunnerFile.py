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