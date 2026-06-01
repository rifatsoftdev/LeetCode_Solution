from typing import List, Optional


class Solution():
    def reverseVowels(self, s):
        vowels = set("aeiouAEIOU")
        l = [char for char in s if char in vowels]
        result = []

        for char in s:
            if char in vowels:
                result.append(l.pop())
            else:
                result.append(char)

        return "".join(result)


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.reverseVowels("IceCreAm"))

    # test cases 2
    print(solution.reverseVowels("leetcode"))
    