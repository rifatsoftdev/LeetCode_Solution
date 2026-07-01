from typing import Optional, List


class Solution:
    def numberOfSteps(self, num: int) -> int:
        steps = 0

        while num > 0:
            if num % 2 == 0:
                num //= 2
            else:
                num -= 1
            steps += 1
        
        return steps
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.numberOfSteps(14))

    # test cases 2
    print(solution.numberOfSteps(8))

    # test cases 3
    print(solution.numberOfSteps(123))