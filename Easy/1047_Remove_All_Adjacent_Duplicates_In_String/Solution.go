package main

import "fmt"

// Past the function from leetcode here
func removeDuplicates(s string) string {
	stack := make([]rune, 0)

	for _, c := range s {
		if len(stack) > 0 && stack[len(stack)-1] == c {
			stack = stack[:len(stack)-1]
		} else {
			stack = append(stack, c)
		}
	}

	return string(stack)
}

func main() {
	// test cases 1
	s1 := "abbaca"
	fmt.Println(removeDuplicates(s1))

	// test cases 2
	s2 := "azxxzy"
	fmt.Println(removeDuplicates(s2))
}
