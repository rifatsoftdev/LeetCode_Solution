package main

import "fmt"

// Past the function from leetcode here
func removeStars(s string) string {
	st := []rune{}

	for _, c := range s {
		if c == '*' && len(st) > 0 {
			st = st[:len(st)-1]
		} else if c != '*' {
			st = append(st, c)
		}
	}

	return string(st)
}

func main() {
	// test cases 1
	s1 := "leet**cod*e"
	fmt.Println(removeStars(s1))

	// test cases 2
	s2 := "erase*****"
	fmt.Println(removeStars(s2))
}
