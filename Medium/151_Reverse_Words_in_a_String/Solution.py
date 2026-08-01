from typing import List, Optional


class Solution(object):
    def reverseWords(self, s: str) -> str:
        l = (s.split(" "))

        while ("" in l):
            l.remove("")
        
        l = l[::-1]

        ans = ""
        for i in l:
            ans += (i + " ")

        return ans[:-1]


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s = "the sky is blue"
    print(solution.reverseWords(s))  # Output: "blue is sky the"

    # test cases 2
    s = "  hello world  "
    print(solution.reverseWords(s))  # Output: "world hello"