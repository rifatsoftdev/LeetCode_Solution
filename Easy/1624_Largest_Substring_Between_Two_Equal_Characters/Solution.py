from typing import List, Optional


class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        char_indices = {}
        max_len = -1
        
        for i, char in enumerate(s):
            if char in char_indices:
                max_len = max(max_len, i - char_indices[char] - 1)
            else:
                char_indices[char] = i
                
        return max_len
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.maxLengthBetweenEqualCharacters("aa"))   # 0
    
    # test cases 2
    print(solution.maxLengthBetweenEqualCharacters("abca")) # 2

    # test cases 3
    print(solution.maxLengthBetweenEqualCharacters("cbzxy")) # -1
    
    
    