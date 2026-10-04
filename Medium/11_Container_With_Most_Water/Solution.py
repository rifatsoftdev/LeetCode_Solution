from typing import List, Optional


class Solution:
    def maxArea(self, height: list[int]) -> int:
        result = 0
        left = 0
        right = len(height) - 1

        while (left < right):
            w = right - left
            h = min(height[left], height[right])
            a = w * h
            result = max(a, result)

            if (height[left] < height[right]):
                left += 1
            else:
                right -= 1

        return result
        

if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    height1 = [1,8,6,2,5,4,8,3,7]
    print(solution.maxArea(height1))

    # test cases 2
    height2 = [1,1]
    print(solution.maxArea(height2))
    