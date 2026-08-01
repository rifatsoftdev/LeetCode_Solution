


class Solution:
    def isBalanced(self, num: str) -> bool:
        even_sum = 0
        odd_sum = 0
        
        for i, digit in enumerate(num):
            if i % 2 == 0:
                even_sum += int(digit)
            else:
                odd_sum += int(digit)
        
        return even_sum == odd_sum


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.isBalanced("1234"))  # Output: False

    # test cases 2
    print(solution.isBalanced("24123"))  # Output: True