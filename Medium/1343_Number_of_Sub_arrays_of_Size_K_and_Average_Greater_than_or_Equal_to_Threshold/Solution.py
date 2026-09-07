from typing import List, Optional


class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        sum = 0
        ans = 0

        for i in range(k):
            sum += arr[i]

        if (sum >= threshold * k):
            ans += 1


        for i in range(k, len(arr)):
            sum -= arr[i-k]
            sum += arr[i]

            if (sum >= threshold * k):
                ans += 1

        return ans
        

if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    arr1 = [2,2,2,2,5,5,5,8]
    k1 = 3
    threshold1 = 4
    print(solution.numOfSubarrays(arr1, k1, threshold1))

    # test cases 2
    arr2 = [11,13,17,23,29,31,7,5,2,3]
    k2 = 3
    threshold2 = 5
    print(solution.numOfSubarrays(arr2, k2, threshold2))
    
    
    