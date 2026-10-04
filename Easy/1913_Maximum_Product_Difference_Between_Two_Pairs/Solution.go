package main

import (
	"fmt"
	"sort"
)

func maxProductDifference(nums []int) int {
	sort.Ints(nums)
	n := len(nums)

	return (nums[n-1] * nums[n-2]) - (nums[0] * nums[1])
}

func main() {
	// test cases 1
	nums1 := []int{5, 6, 2, 7, 4}
	fmt.Println(maxProductDifference(nums1)) // Output: 34

	// test cases 2
	nums2 := []int{4, 2, 5, 9, 7, 4, 8}
	fmt.Println(maxProductDifference(nums2)) // Output: 64
}
