package main

import "fmt"

// Past the function from leetcode here
func findMissingElements(nums []int) []int {
	missing := []int{}
	countMap := make(map[int]int)

	minNum := nums[0]
	maxNum := nums[0]

	for _, num := range nums {
		countMap[num]++

		if num < minNum {
			minNum = num
		}
		if num > maxNum {
			maxNum = num
		}
	}

	for i := minNum; i <= maxNum; i++ {
		if _, found := countMap[i]; !found {
			missing = append(missing, i)
		}
	}

	return missing
}

func main() {
	// test cases 1
	nums1 := []int{1, 4, 2, 5}
	missing1 := findMissingElements(nums1)
	fmt.Println(missing1)

	// test cases 2
	nums2 := []int{7, 8, 6, 9}
	missing2 := findMissingElements(nums2)
	fmt.Println(missing2)

	// test cases 3
	nums3 := []int{5, 1}
	missing3 := findMissingElements(nums3)
	fmt.Println(missing3)

}
