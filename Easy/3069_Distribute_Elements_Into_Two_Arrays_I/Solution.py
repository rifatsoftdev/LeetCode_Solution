from typing import List, Optional


class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1 = []
        arr2 = []

        arr1Last = nums[0]
        arr2Last = nums[1]

        arr1.append(nums[0])
        arr2.append(nums[1])

        for i in range(2, len(nums)):
            if (arr1Last > arr2Last):
                arr1.append(nums[i])
                arr1Last = nums[i]
            else:
                arr2.append(nums[i])
                arr2Last = nums[i]

        return arr1 + arr2


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums = [2,1,3]
    print(solution.resultArray(nums))

    # test cases 2
    nums = [5,4,3,8]
    print(solution.resultArray(nums))
    