

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        n = len(s)

        for i in range(n):
            rotate = s[i::] + s[0:i:]

            if (rotate == goal):
                return True
        
        return False


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    s1 = "abcde"
    goal1 = "cdeab"
    print(solution.rotateString(s1, goal1))
        
    # test cases 2
    s2 = "abcde"
    goal2 = "abced"
    print(solution.rotateString(s2, goal2))