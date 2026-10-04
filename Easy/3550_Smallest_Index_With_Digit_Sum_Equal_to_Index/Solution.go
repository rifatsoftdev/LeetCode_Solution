package main

import "fmt"

// Past the function from leetcode here
func smallestIndex(nums []int) int {
	for i := 0; i < len((nums)); i++ {
		if i == sumFoDigit(nums[i]) {
			return i
		}
	}

	return -1
}

func sumFoDigit(n int) int {
	ans := 0

	for n != 0 {
		d := n % 10
		ans += d
		n /= 10
	}

	return ans
}

func main() {
	// test cases 1
	nums1 := []int{1, 3, 2}
	fmt.Println(smallestIndex(nums1))

	// test cases 2
	nums2 := []int{1, 10, 11}
	fmt.Println(smallestIndex(nums2))

	// test cases 3
	nums3 := []int{1, 2, 3}
	fmt.Println(smallestIndex(nums3))

}
