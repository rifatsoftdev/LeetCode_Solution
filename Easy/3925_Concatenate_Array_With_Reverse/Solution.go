package main

import "fmt"

// Past the function from leetcode here
func concatWithReverse(nums []int) []int {
	result := make([]int, 0, len(nums)*2)
	result = append(result, nums...)

	for i := len(nums) - 1; i >= 0; i-- {
		result = append(result, nums[i])
	}

	return result
}

func main() {
	// test cases 1
	nums1 := []int{1, 2, 3}
	result1 := concatWithReverse(nums1)
	fmt.Println(result1) // Output: [1, 2, 3, 3, 2, 1]

	// test cases 2
	nums2 := []int{1}
	result2 := concatWithReverse(nums2)
	fmt.Println(result2) // Output: [1, 1]
}
