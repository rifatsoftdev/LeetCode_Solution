package main

import "fmt"

// Past the function from leetcode here
func reverseDegree(s string) int {
	degree := 0

	for i := 0; i < len(s); i++ {
		rev := 26 - (int(s[i]) - int('a') + 1) + 1
		degree += (rev * (i + 1))
	}

	return degree
}

func main() {
	// test cases 1
	s1 := "abc"
	result1 := reverseDegree(s1)
	fmt.Println(result1)

	// test cases 2
	s2 := "zaza"
	result2 := reverseDegree(s2)
	fmt.Println(result2)
}
