package main

import "fmt"

// Past the function from leetcode here
func findMiddleIndex(nums []int) int {
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
	nums1 := []int{2, 3, -1, 8, 4}
	fmt.Println(findMiddleIndex(nums1)) // Output: 3

	// test cases 2
	nums2 := []int{1, -1, 4}
	fmt.Println(findMiddleIndex(nums2)) // Output: 2

	// test cases 3
	nums3 := []int{2, 5}
	fmt.Println(findMiddleIndex(nums3)) // Output: -1

}
