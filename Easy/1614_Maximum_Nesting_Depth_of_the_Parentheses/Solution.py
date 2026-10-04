from typing import List, Optional


class Solution:
    def maxDepth(self, s: str) -> int:
        depth = 0
        result = 0

        for char in s:
            if char == '(':
                depth += 1
            elif char == ')':
                depth -= 1

            result = max(result, depth)

        return result

if __name__ == "__main__":
    solution = Solution()

    s1 = "(1+(2*3)+((8)/4))+1"
    print(solution.maxDepth(s1))

    # test cases 2
    s2 = "(1)+((2))+(((3)))"
    print(solution.maxDepth(s2))

    # test cases 3
    s3 = "()(())((()()))"
    print(solution.maxDepth(s3))
    
    