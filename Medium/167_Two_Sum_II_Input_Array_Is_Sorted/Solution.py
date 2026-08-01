from typing import List, Optional


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1

        while (left < right):
            suM = numbers[left] + numbers[right]
            if (suM == target):
                return [left+1, right+1]
            elif (suM > target):
                right -= 1
            else:
                left += 1
        
        return []
    

if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    numbers1 = [2,7,11,15]
    target1 = 9
    print(solution.twoSum(numbers1, target1))

    # test cases 2
    numbers2 = [2,3,4]
    target2 = 6
    print(solution.twoSum(numbers2, target2))

    # test cases 3
    numbers3 = [-1,0]
    target3 = -1
    print(solution.twoSum(numbers3, target3))