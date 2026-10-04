package main

import "fmt"

// Past the function from leetcode here
func runningSum(nums []int) []int {
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i-1]
	}

	return nums
}

func main() {
	// test cases 1
	nums1 := []int{1, 2, 3, 4}
	result1 := runningSum(nums1)
	fmt.Println(result1) // Output: [1,3,6,10]

	// test cases 2
	nums2 := []int{1, 1, 1, 1}
	result2 := runningSum(nums2)
	fmt.Println(result2) // Output: [1,2,3,4]

}
