package main

import "fmt"

// Past the function from leetcode here
func numIdenticalPairs(nums []int) int {
	dic := make(map[int]int)
	count := 0

	for _, num := range nums {
		count += dic[num]
		dic[num]++
	}

	return count
}

func main() {
	// test cases 1
	nums1 := []int{1, 2, 3, 1, 1, 3}
	result1 := numIdenticalPairs(nums1)
	fmt.Println(result1)

	// test cases 2
	nums2 := []int{1, 1, 1, 1}
	result2 := numIdenticalPairs(nums2)
	fmt.Println(result2)

	// test cases 3
	nums3 := []int{1, 2, 3}
	result3 := numIdenticalPairs(nums3)
	fmt.Println(result3)
}
