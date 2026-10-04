package main

import "fmt"

func rotateString(s string, goal string) bool {
	n := len(s)

	for i := 0; i < n; i++ {
		rotate := s[i:] + s[:i]

		if rotate == goal {
			return true
		}
	}

	return false
}

func main() {
	// test cases 1
	s := "abcde"
	goal := "cdeab"
	fmt.Println(rotateString(s, goal)) // Output: true

	// test cases 2
	s = "abcde"
	goal = "abced"
	fmt.Println(rotateString(s, goal)) // Output: false
}
