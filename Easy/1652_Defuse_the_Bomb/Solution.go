package main

import "fmt"

// Past the function from leetcode here
func decrypt(code []int, k int) []int {
	n := len(code)
	ans := make([]int, n)

	if k == 0 {
		return ans
	}

	for i := 0; i < n; i++ {
		sum := 0

		if k > 0 {
			for j := 1; j <= k; j++ {
				sum += code[(i+j)%n]
			}
		} else {
			for j := 1; j <= -k; j++ {
				sum += code[(i-j+n)%n]
			}
		}

		ans[i] = sum
	}

	return ans
}

func main() {
	// test case 1
	code1 := []int{5, 7, 1, 4}
	result1 := decrypt(code1, 3)
	fmt.Println(result1)

	// test case 2
	code2 := []int{1, 2, 3, 4}
	result2 := decrypt(code2, 0)
	fmt.Println(result2)

	// test case 3
	code3 := []int{2, 4, 9, 3}
	result3 := decrypt(code3, -2)
	fmt.Println(result3)
}
