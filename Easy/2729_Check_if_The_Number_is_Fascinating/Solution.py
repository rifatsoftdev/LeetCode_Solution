from typing import List, Optional


class Solution:
    def isFascinating(self, n: int) -> bool:
        s = str(n)
        s += str(n*2)
        s += str(n*3)
        s = set(s)

        if (len(s) != 9 or "0" in s):
            return False
        
        return True



if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    # test cases 2
    
    