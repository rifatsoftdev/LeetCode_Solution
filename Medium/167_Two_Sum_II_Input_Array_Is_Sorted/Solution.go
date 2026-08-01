package main

import "fmt"

// Past the function from leetcode here
func twoSum(numbers []int, target int) []int {
	left := 0
	right := len(numbers) - 1

	for left < right {
		sum := numbers[left] + numbers[right]

		if sum == target {
			return []int{left + 1, right + 1}
		} else if sum < target {
			left++
		} else {
			right--
		}
	}

	return []int{}
}

func main() {
	// test cases 1
	numbers1 := []int{2, 7, 11, 15}
	target1 := 9
	fmt.Println(twoSum(numbers1, target1))

	// test cases 2
	numbers2 := []int{2, 3, 4}
	target2 := 6
	fmt.Println(twoSum(numbers2, target2))

	// test cases 3
	numbers3 := []int{-1, 0}
	target3 := -1
	fmt.Println(twoSum(numbers3, target3))
}
