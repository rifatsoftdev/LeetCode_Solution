from typing import List, Optional


class Solution:
    def removeDuplicates(self, s: str) -> str:
        st = []

        for i in s:
            if st and st[-1] == i:
                st.pop()
            else:
                st.append(i)

        return "".join(st)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "abbaca"
    print(solution.removeDuplicates(s1))

    # test cases 2
    s2 = "azxxzy"
    print(solution.removeDuplicates(s2))