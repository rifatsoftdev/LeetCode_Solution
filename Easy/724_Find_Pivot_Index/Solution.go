package main

import "fmt"

// Past the function from leetcode here
func pivotIndex(nums []int) int {
	totalSum := 0

	for _, num := range nums {
		totalSum += num
	}

	leftSum := 0

	for i, num := range nums {
		if leftSum == (totalSum - leftSum - num) {
			return i
		}
		leftSum += num
	}

	return -1
}

func main() {
	// test cases 1
	nums1 := []int{1, 7, 3, 6, 5, 6}
	fmt.Println(pivotIndex(nums1)) // Output: 3

	// test cases 2
	nums2 := []int{1, 2, 3}
	fmt.Println(pivotIndex(nums2)) // Output: -1

	// test cases 3
	nums3 := []int{2, 1, -1}
	fmt.Println(pivotIndex(nums3)) // Output: 0

}
