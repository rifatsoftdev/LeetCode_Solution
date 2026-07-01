from typing import List, Optional


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        child = 0
        cookie = 0

        while (child < len(g) and cookie < len(s)):
            if (s[cookie] >= g[child]):
                child += 1
            
            cookie += 1
        
        return child


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    g1 = [1, 2, 3]
    s1 = [1, 1]
    print(solution.findContentChildren(g1, s1))  # Expected output: 1
    
    # test cases 2
    g2 = [1, 2]
    s2 = [1, 2, 3]
    print(solution.findContentChildren(g2, s2))  # Expected output: 2
    
    