package main

import "sort"

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)

	chile := 0
	cookie := 0

	for chile < len(g) && cookie < len(s) {
		if g[chile] <= s[cookie] {
			chile++
		}
		cookie++
	}

	return chile
}

func main() {
	// test cases 1
	g := []int{1, 2, 3}
	s := []int{1, 1}
	result := findContentChildren(g, s)
	println(result) // Output: 1

	// test cases 2
	g = []int{1, 2}
	s = []int{1, 2, 3}
	result = findContentChildren(g, s)
	println(result) // Output: 2
}
