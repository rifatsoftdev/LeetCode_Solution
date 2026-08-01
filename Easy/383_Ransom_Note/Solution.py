import collections


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        m = collections.Counter(magazine)

        for char in ransomNote:
            if m[char] == 0:
                return False
            m[char] -= 1

        return True


if __name__ == "__main__":
    sol = Solution()

    # test cases 1
    ransomNote1 = "a"
    magazine1 = "b"
    print(sol.canConstruct(ransomNote1, magazine1))

    # test cases 2
    ransomNote2 = "aa"
    magazine2 = "ab"
    print(sol.canConstruct(ransomNote2, magazine2))

    # test cases 3
    ransomNote3 = "aa"
    magazine3 = "aab"
    print(sol.canConstruct(ransomNote3, magazine3))