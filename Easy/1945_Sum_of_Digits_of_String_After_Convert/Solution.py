

class Solution:
    def getLucky(self, s: str, k: int) -> int:
        numStr = ""

        for c in s:
            numStr += str(ord(c) - ord('a') + 1)
        
        for _ in range(k):
            sum = 0

            for c in numStr:
                sum += int(c)
            
            numStr = str(sum)
        
        return int(numStr)


if __name__ == "__main__":
    solution = Solution()
    
    # test cases 1
    print(solution.getLucky("iiii", 1))

    # test cases 2
    print(solution.getLucky("leetcode", 2))

    # test cases 3
    print(solution.getLucky("zbax", 2))
        
        