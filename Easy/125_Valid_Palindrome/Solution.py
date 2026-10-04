from typing import List, Optional


class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while (left < right):
            if (not s[left].isalnum()):
                left += 1
            elif (not s[right].isalnum()):
                right -= 1
            else:
                if (s[left].lower() != s[right].lower()):
                    return False
                else:
                    left += 1
                    right -= 1

        return True


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "A man, a plan, a canal: Panama"
    print(solution.isPalindrome(s1))

    # test cases 2
    s2 = "race a car"
    print(solution.isPalindrome(s2))

    # test cases 3
    s3 = " "
    print(solution.isPalindrome(s3))