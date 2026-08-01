from typing import List, Optional


class Solution:
    def interpret(self, command: str) -> str:
        result = ""

        i = 0
        while i < len(command):
            if command[i] == 'G':
                result += 'G'
            elif command[i] == '(' and i + 1 < len(command) and command[i + 1] == ')':
                result += "o"
                i += 1
            elif command[i] == '(' and i + 3 < len(command) and command[i + 1] == 'a' and command[i + 2] == 'l' and command[i + 3] == ')':
                result += "al"
                i += 3
            i += 1

        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.interpret("G()(al)"))  # Output: Goal
    
    # test cases 2
    print(solution.interpret("G()()()()(al)"))  # Output: Gooooal

    # test cases 3
    print(solution.interpret("(al)G(al)()()G"))  # Output: alGalooG