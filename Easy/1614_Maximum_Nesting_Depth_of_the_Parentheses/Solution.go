package main

import "fmt"

// Past the function from leetcode here
func maxDepth(s string) int {
	result := 0
	o := 0
	c := 0

	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			o++
		}

		if s[i] == ')' {
			c++
		}

		if o-c > result {
			result = o - c
		}
	}

	return result
}

func main() {
	// test cases 1
	s1 := "(1+(2*3)+((8)/4))+1"
	fmt.Println(maxDepth(s1))

	// test cases 2
	s2 := "(1)+((2))+(((3)))"
	fmt.Println(maxDepth(s2))

	// test cases 3
	s3 := "()(())((()()))"
	fmt.Println(maxDepth(s3))

}
