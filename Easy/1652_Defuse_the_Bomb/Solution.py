from typing import List, Optional


class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n

        if (k == 0):
            return ans

        for i in range(n):
            total = 0

            if k > 0:
                for j in range(1, k + 1):
                    total += code[(i + j) % n]
            else:
                for j in range(1, abs(k) + 1):
                    total += code[(i - j) % n]

            ans[i] = total

        return ans


if __name__ == "__main__":
    solution = Solution()

    # test case 1
    code1 = [5, 7, 1, 4]
    result1 = solution.decrypt(code1, 3)
    print(result1)

    # test case 2
    code2 = [1, 2, 3, 4]
    result2 = solution.decrypt(code2, 0)
    print(result2)

    # test case 3
    code3 = [2, 4, 9, 3]
    result3 = solution.decrypt(code3, -2)
    print(result3)
    