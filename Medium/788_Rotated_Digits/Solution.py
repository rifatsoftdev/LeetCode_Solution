

class Solution:
    def rotatedDigits(self, n: int) -> int:
        count = 0

        for num in range(1, n + 1):
            s = str(num)
            is_valid = True
            is_different = False

            for ch in s:
                if ch in '347':
                    is_valid = False
                    break
                if ch in '2569':
                    is_different = True

            if is_valid and is_different:
                count += 1

        return count


if __name__ == "__main__":
    solution = Solution()
    
    # test cases 1
    print(solution.rotatedDigits(10))

    # test cases 2
    print(solution.rotatedDigits(1))

    # test cases 3
    print(solution.rotatedDigits(2))
        
        