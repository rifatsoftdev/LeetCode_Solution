from typing import List, Optional


class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff = float('inf')
        result = []

        for i in range(1, len(arr)):
            diff = arr[i] - arr[i - 1]
            if diff < min_diff:
                min_diff = diff
                result = [[arr[i - 1], arr[i]]]
            elif diff == min_diff:
                result.append([arr[i - 1], arr[i]])

        return result


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.minimumAbsDifference([4, 2, 1, 3]))

    # test cases 2
    print(solution.minimumAbsDifference([1, 3, 6, 10, 15]))

    # test cases 3
    print(solution.minimumAbsDifference([3, 8, -10, 23, 19, -4, -14, 27]))