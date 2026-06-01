from typing import List, Optional


class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        firstUpper = [-1] * 26
        lastLower = [-1] * 26

        for i in range(len(word)):
            c = word[i]

            if (c.islower()):
                lastLower[ord(c) - ord('a')] = i
            
            else:
                if (firstUpper[ord(c) - ord('A')] == -1):
                    firstUpper[ord(c) - ord('A')] = i
        
        count = 0

        for i in range(26):
            if (lastLower[i] != -1 and firstUpper[i] != -1 and lastLower[i] < firstUpper[i]):
                count += 1
        
        return count
            


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.numberOfSpecialChars("aaAbcBC"))

    # test cases 2
    print(solution.numberOfSpecialChars("abc"))

    # test cases 3
    print(solution.numberOfSpecialChars("AbBCab"))
    
    