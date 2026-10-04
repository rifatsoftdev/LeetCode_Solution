package main

import "fmt"

// Past the function from leetcode here
func maxArea(height []int) int {
	result := 0
	left := 0
	right := len((height)) - 1

	for left < right {
		w := right - left
		h := min(height[left], height[right])
		a := w * h

		result = max(result, a)

		if height[left] < height[right] {
			left++
		} else {
			right--
		}

	}

	return result
}

func main() {
	// test cases 1
	height1 := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	fmt.Println(maxArea(height1))

	// test cases 2
	height2 := []int{1, 1}
	fmt.Println(maxArea(height2))

}
