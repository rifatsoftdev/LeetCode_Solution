package main

import "fmt"

// Past the function from leetcode here
func firstMatchingIndex(s string) int {
	left := 0
	right := len(s) - 1

	for left <= right {
		if s[left] == s[right] {
			return left
		}

		left++
		right--
	}

	return -1
}

func main() {
	// test cases 1
	s1 := "abcacbd"
	fmt.Println(firstMatchingIndex(s1))

	//  test cases 2
	s2 := "abc"
	fmt.Println(firstMatchingIndex(s2))

	//  test cases 3
	s3 := "abcdab"
	fmt.Println(firstMatchingIndex(s3))

}
