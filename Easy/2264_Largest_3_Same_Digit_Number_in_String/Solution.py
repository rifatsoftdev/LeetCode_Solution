from typing import List, Optional


class Solution:
    def largestGoodInteger(self, num: str) -> str:
        res = ""

        for i in range(len(num) - 2):
            if num[i] == num[i+1] == num[i+2]:
                res = max(res, num[i:i+3])

        return res
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    num = "6777133339"
    print(solution.largestGoodInteger(num))
    
    # test cases 2
    num = "2300019"
    print(solution.largestGoodInteger(num))
    
    # test cases 3
    num = "42352338"
    print(solution.largestGoodInteger(num))
    
    