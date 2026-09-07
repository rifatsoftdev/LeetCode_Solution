from typing import List, Optional


class Solution:
    def countSeniors(self, details: List[str]) -> int:
        count = 0

        for detail in details:
            age = int(detail[11:13])
            if age > 60:
                count += 1

        return count


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    details1 = ["7868190130M7522", "5303914400F9211", "9273338290F4010"]
    print(solution.countSeniors(details1))  # Output: 2

    # test cases 2
    details2 = ["1313579440F2036", "2921522980M5644"]
    print(solution.countSeniors(details2))  # Output: 0
    