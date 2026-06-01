from typing import List, Optional


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        ans = []
        seen = set()
        common_count = 0
        
        for i in range(n):
            if A[i] in seen:
                common_count += 1
            else:
                seen.add(A[i])
                
            if B[i] in seen:
                common_count += 1
            else:
                seen.add(B[i])
                
            ans.append(common_count)
            
        return ans
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    A1 = [1,3,2,4]
    B1 = [3,1,2,4]
    print(solution.findThePrefixCommonArray(A1, B1))

    # test cases 2
    A2 = [2,3,1]
    B2 = [3,1,2]
    print(solution.findThePrefixCommonArray(A2, B2))
    