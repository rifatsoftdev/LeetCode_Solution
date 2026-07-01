from typing import List, Optional


class Solution:
    def convertDateToBinary(self, date: str) -> str:
        date = date.split("-")
        
        for i in range(3):
            date[i] = bin(int(date[i]))[2:]
        
        return "-".join(date)



if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    print(solution.convertDateToBinary("2080-02-29"))

    # test cases 2
    print(solution.convertDateToBinary("1900-01-01"))
    
    