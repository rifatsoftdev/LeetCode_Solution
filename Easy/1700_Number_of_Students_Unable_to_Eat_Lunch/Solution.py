from typing import List, Optional


class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        zero = 0
        one = 0

        for student in students:
            if (student == 0):
                zero += 1
            else:
                one += 1

        for sandwich in sandwiches:
            if (sandwich == 0):
                if (zero == 0):
                    return one
                zero -= 1
            else:
                if (one == 0):
                    return zero
                one -= 1

        return 0


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    students1 = [1, 1, 0, 0]
    sandwiches1 = [0, 1, 0, 1]
    print(solution.countStudents(students1, sandwiches1))  # Output: 0

    # test cases 2
    students2 = [1, 1, 1, 0, 0, 1]
    sandwiches2 = [1, 0, 0, 0, 1, 1]
    print(solution.countStudents(students2, sandwiches2))  # Output: 3
    
    