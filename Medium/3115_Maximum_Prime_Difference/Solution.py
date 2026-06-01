from typing import List, Optional


class Solution:
    def isPrime(self, n: int) -> bool:
        if n <= 1:
            return False
        
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        
        return True
    
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        left_prime: Optional[int] = None
        right_prime: Optional[int] = None
        
        for i in range(len(nums)):
            if self.isPrime(nums[i]):
                left_prime = i
                break
        
        for i in range(len(nums) - 1, -1, -1):
            if self.isPrime(nums[i]):
                right_prime = i
                break
        
        
        return right_prime - left_prime


if __name__ == "__main__":
    solution = Solution()
    
    # test cases 1
    nums1 = [4, 2, 9, 5, 3]
    print(solution.maximumPrimeDifference(nums1))  # Output: 3

    # test cases 2
    nums2 = [4, 8, 2, 8]
    print(solution.maximumPrimeDifference(nums2))  # Output: 0
        
        