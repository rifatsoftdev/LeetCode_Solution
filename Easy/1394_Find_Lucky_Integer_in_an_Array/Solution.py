from typing import List, Optional


class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counts = {}

        for num in arr:
            counts[num] = counts.get(num, 0) + 1
        
        lucky_integer = -1

        for num, freq in counts.items():
            if num == freq:
                lucky_integer = max(lucky_integer, num)
                
        return lucky_integer
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    arr1 = [2, 2, 3, 4]
    print(solution.findLucky(arr1))  # Output: 2
    
    # test cases 2
    arr2 = [1, 2, 2, 3, 3, 3]
    print(solution.findLucky(arr2))  # Output: 3

    # test cases 3
    arr3 = [2, 2, 2, 3, 3]
    print(solution.findLucky(arr3))  # Output: -1
    
    
    