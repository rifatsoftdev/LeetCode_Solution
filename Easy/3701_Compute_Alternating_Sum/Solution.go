package main

import "fmt"

// Past the function from leetcode here
func alternatingSum(nums []int) int {
	total := 0

	for i := 0; i < len(nums); i++ {
		if i%2 == 0 {
			total += nums[i]
		} else {
			total -= nums[i]
		}
	}

	return total
}

func main() {
	// test cases 1
	nums1 := []int{1, 3, 5, 7}
	fmt.Println(alternatingSum(nums1)) // Output: -4

	// test cases 2
	nums2 := []int{100}
	fmt.Println(alternatingSum(nums2)) // Output: 100
}
