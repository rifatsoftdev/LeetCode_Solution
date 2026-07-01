from typing import List, Optional


class Solution:
    def isZero(n) -> bool:
        return '0' in str(n)
        
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for a in range(1, n):
            b = n - a
            if '0' not in str(a) and '0' not in str(b):
                return [a, b]
            
        return []
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    n1 = 2
    print(solution.getNoZeroIntegers(n1))
    
    # test cases 2
    n2 = 11
    print(solution.getNoZeroIntegers(n2))
    
    