package main

import "fmt"

// Past the function from leetcode here
func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	writeIndex := 1
	count := 1

	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			count++
		} else {
			count = 1
		}

		if count <= 2 {
			nums[writeIndex] = nums[i]
			writeIndex++
		}
	}

	return writeIndex
}

func main() {
	// test cases 1
	nums1 := []int{1, 1, 1, 2, 2, 3}
	fmt.Println(removeDuplicates(nums1)) // Output: 5

	// test cases 2
	nums2 := []int{0, 0, 1, 1, 1, 1, 2, 3, 3}
	fmt.Println(removeDuplicates(nums2)) // Output: 7

}
