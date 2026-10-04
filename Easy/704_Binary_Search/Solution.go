package main

import "fmt"

// Past the function from leetcode here
func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1

	for left <= right {
		mid := left + (right-left)/2

		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return -1
}

func main() {
	// test cases 1
	nums1 := []int{-1, 0, 3, 5, 9, 12}
	target1 := 9
	result1 := search(nums1, target1)
	fmt.Println(result1)

	// test cases 2
	nums2 := []int{-1, 0, 3, 5, 9, 12}
	target2 := 2
	result2 := search(nums2, target2)
	fmt.Println(result2)

}
