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

        for n in arr2:
            arr1.append(n)

        return arr1