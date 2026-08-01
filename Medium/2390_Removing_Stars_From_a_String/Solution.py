from typing import List, Optional


class Solution:
    def removeStars(self, s: str) -> str:
        st = []
        
        for c in s:
            if c == '*':
                if st:
                    st.pop()
            else:
                st.append(c)
        
        return ''.join(st)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "leet**cod*e"
    print(solution.removeStars(s1))

    # test cases 2
    s2 = "erase*****"
    print(solution.removeStars(s2))