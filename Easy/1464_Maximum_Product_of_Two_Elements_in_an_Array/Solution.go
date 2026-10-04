package main

import (
	"fmt"
	"sort"
)

// Past the function from leetcode here
func maxProduct(nums []int) int {
	sort.Ints(nums)
	n := len(nums)

	return (nums[n-1] - 1) * (nums[n-2] - 1)
}

func main() {
	// test cases 1
	nums1 := []int{3, 4, 5, 2}
	fmt.Println(maxProduct(nums1)) // Output: 12

	// test cases 2
	nums2 := []int{1, 5, 4, 5}
	fmt.Println(maxProduct(nums2)) // Output: 16
}
