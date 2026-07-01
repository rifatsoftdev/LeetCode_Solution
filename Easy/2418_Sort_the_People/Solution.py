from typing import List, Optional


class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        for i in range(len(heights)):
            max_idx = i
            for j in range(i + 1, len(heights)):
                if heights[j] > heights[max_idx]:
                    max_idx = j
            
            heights[i], heights[max_idx] = heights[max_idx], heights[i]
            names[i], names[max_idx] = names[max_idx], names[i]
            
        return names
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    names1 = ["Mary", "John", "Emma"]
    heights1 = [180, 165, 170]
    print(solution.sortPeople(names1, heights1))

    # test cases 2
    names2 = ["Alice", "Bob", "Bob"]
    heights2 = [155, 185, 150]
    print(solution.sortPeople(names2, heights2))
    
    
    