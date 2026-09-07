package main

import "fmt"

// Past the function from leetcode here
func countQuadruplets(nums []int) int {
	count := 0
	n := len(nums)

	for a := 0; a < n-3; a++ {
		for b := a + 1; b < n-2; b++ {
			for c := b + 1; c < n-1; c++ {
				for d := c + 1; d < n; d++ {
					if nums[a]+nums[b]+nums[c] == nums[d] {
						count++
					}
				}
			}
		}
	}

	return count
}

func main() {
	// test cases 1
	nums1 := []int{1, 2, 3, 6}
	fmt.Println(countQuadruplets(nums1)) // Output: 1

	// test cases 2
	nums2 := []int{3, 3, 6, 4, 5}
	fmt.Println(countQuadruplets(nums2)) // Output: 0

	// test cases 3
	nums3 := []int{1, 1, 1, 3, 5}
	fmt.Println(countQuadruplets(nums3)) // Output: 4
}
