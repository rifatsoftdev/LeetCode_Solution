from typing import List, Optional


class Solution:
    def isPrimr(self, num):
        if num < 2:
            return False
        for i in range(2, int(num**0.5) + 1):
            if num % i == 0:
                return False
        return True
        
    def completePrime(self, num: int) -> bool:
        s_num = str(num)
        
        # suffix
        for i in range(len(s_num)):
            if not self.isPrimr(int(s_num[i:])):
                return False
                
        # prefix
        for i in range(1, len(s_num) + 1):
            if not self.isPrimr(int(s_num[:i])):
                return False
        
        return True
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.completePrime(23))

    # test cases 2
    print(solution.completePrime(39))

    # test cases 3
    print(solution.completePrime(7))
    