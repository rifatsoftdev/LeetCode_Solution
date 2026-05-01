


class Solution:
    def minMaxDifference(self, num: int) -> int:
        fast = ""
        maxNum = ""
        minNum = ""
        s = str(num)

        for i in s:
            if (i != "9"):
                fast = i
                break
        
        for i in s:
            if (i == fast):
                maxNum += "9"
            else:
                maxNum += i
        
        for i in s:
            if (i != "0"):
                fast = i
                break

        for i in s:
            if (i == fast):
                minNum += "0"
            else:
                minNum += i
             
        return int(maxNum) - int(minNum)


if __name__ == "__main__":
    solution = Solution()

    
    # test cases 1
    print(solution.minMaxDifference(11891)) # 99009

    # test cases 2
    print(solution.minMaxDifference(90)) # 99