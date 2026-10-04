from typing import List, Optional


class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        arr = [False] * 26

        for c in allowed:
            arr[ord(c)-97] = True

        result = 0

        for s in words:
            flag = True

            for c in s:
                if (not arr[ord(c) - 97]):
                    flag = False
                    break

            if (flag):
                result += 1

        return result

if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    allowed1 = "ab";
    words1 = ["ad","bd","aaab","baa","badab"];
    print(solution.countConsistentStrings(allowed1, words1))

    # test cases 2
    allowed2 = "abc";
    words2 = ["a","b","c","ab","ac","bc","abc"];
    print(solution.countConsistentStrings(allowed2, words2))

    # test cases 3
    allowed3 = "cad";
    words3 = ["cc","acd","b","ba","bac","bad","ac","d"];
    print(solution.countConsistentStrings(allowed3, words3))
    
    