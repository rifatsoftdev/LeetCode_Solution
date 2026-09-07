package main

import "fmt"

// Past the function from leetcode here
func minOperations(nums []int, k int) int {
	sum := 0

	for i := 0; i < len(nums); i++ {
		sum += nums[i]
	}

	return sum % k
}

func main() {
	// test cases 1
	nums1 := []int{3, 9, 7}
	k1 := 5
	fmt.Println(minOperations(nums1, k1))

	// test cases 2
	nums2 := []int{4, 1, 3}
	k2 := 4
	fmt.Println(minOperations(nums2, k2))

	// test cases 3
	nums3 := []int{3, 2}
	k3 := 6
	fmt.Println(minOperations(nums3, k3))

}
