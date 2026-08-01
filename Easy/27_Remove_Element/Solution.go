package main

import "fmt"

func removeElement(nums []int, val int) int {
	ans := 0

	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[ans] = nums[i]
			ans++
		}
	}

	return ans
}

func main() {
	// test cases 1
	nums1 := []int{3, 2, 2, 3}
	val1 := 3
	fmt.Println(removeElement(nums1, val1)) // Output: 2

	// test cases 2
	nums2 := []int{0, 1, 2, 2, 3, 0, 4, 2}
	val2 := 2
	fmt.Println(removeElement(nums2, val2)) // Output: 5
}
