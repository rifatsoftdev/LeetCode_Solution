


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ans = ""
        flag = True

        for i in s[::-1]:
            if (i == " " and flag):
                continue
            else:
                flag = False
                if (i != " "):
                    ans += i
                else:
                    break
        
        return len(ans)


if __name__ == "__main__":
    solution = Solution()

    # Test cases 1
    print(solution.lengthOfLastWord("Hello World"))

    # Test cases 2
    print(solution.lengthOfLastWord("   fly me   to   the moon  "))

    # Test cases 3
    print(solution.lengthOfLastWord("luffy is still joyboy"))