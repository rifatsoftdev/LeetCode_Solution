from typing import List, Optional


class Solution:
    def secondHighest(self, s: str) -> int:
        fastLarge = -1
        secendLarge = -1

        for char in s:
            if char.isdigit():
                digit = int(char)

                if digit > fastLarge:
                    secendLarge = fastLarge
                    fastLarge = digit
                elif fastLarge > digit > secendLarge:
                    secendLarge = digit
        
        return secendLarge
         


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "dfa12321afd"
    print(solution.secondHighest(s1))

    # test cases 2
    s2 = "abc1111"
    print(solution.secondHighest(s2))
    
    
    
    