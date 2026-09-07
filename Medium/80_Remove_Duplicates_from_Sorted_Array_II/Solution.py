from typing import List, Optional


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        write_index = 1
        count = 1

        for read_index in range(1, len(nums)):
            if nums[read_index] == nums[read_index - 1]:
                count += 1
            else:
                count = 1

            if count <= 2:
                nums[write_index] = nums[read_index]
                write_index += 1

        return write_index


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    nums1 = [1, 1, 1, 2, 2, 3]
    print(solution.removeDuplicates(nums1))  # Output: 5
    
    # test cases 2
    nums2 = [0, 0, 1, 1, 1, 1, 2, 3, 3]
    print(solution.removeDuplicates(nums2))  # Output: 7
    