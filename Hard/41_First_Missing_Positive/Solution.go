package main

import (
	"fmt"
	"slices"
)

func firstMissingPositive(nums []int) int {
	slices.Sort(nums)
	target := 1

	for _, num := range nums {
		if num == target {
			target++
		} else if num > target {
			break
		}
	}

	return target
}

func main() {
	// test cases 1
	nums1 := []int{1, 2, 0}
	fmt.Println(firstMissingPositive(nums1))

	// test cases 2
	nums2 := []int{3, 4, -1, 1}
	fmt.Println(firstMissingPositive(nums2))

	// test cases 3
	nums3 := []int{7, 8, 9, 11, 12}
	fmt.Println(firstMissingPositive(nums3))
}
