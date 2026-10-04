from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        write = 0
        read = 0
        n = len(chars)

        while read < n:
            char = chars[read]
            count = 0

            while read < n and chars[read] == char:
                read += 1
                count += 1

            chars[write] = char
            write += 1

            if count > 1:
                for digit in str(count):
                    chars[write] = digit
                    write += 1

        return write


if __name__ == "__main__":
    solution = Solution()

    # test case 1
    chars = ["a", "a", "b", "b", "c", "c", "c"]
    result = solution.compress(chars)
    print(result, chars[:result])

    # test case 2
    chars = ["a"]
    result = solution.compress(chars)
    print(result, chars[:result])

    # test case 3
    chars = ["a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b"]
    result = solution.compress(chars)
    print(result, chars[:result])