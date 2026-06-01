from typing import List, Optional


class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1] - x[0], reverse=True)

        current_energy = 0
        initial_energy = 0

        for actual, minimum in tasks:
            if current_energy < minimum:
                initial_energy += (minimum - current_energy)
                current_energy = minimum

            current_energy -= actual
        
        return initial_energy


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    tasks1 = [[1,2],[2,4],[4,8]]
    print(solution.minimumEffort(tasks1))  # expected output: 8

    # test cases 2
    tasks2 = [[1,3],[2,4],[10,11],[10,12],[8,9]]
    print(solution.minimumEffort(tasks2))  # expected output: 32

    # test cases 3
    tasks3 = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
    print(solution.minimumEffort(tasks3))  # expected output: 27
        
        