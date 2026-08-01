package main

import "fmt"

// Past the function from leetcode here
func maxProduct(n int) int {
	firstLarge := 0
	secondLarge := 0

	for n != 0 {
		digit := n % 10

		if digit > firstLarge {
			secondLarge = firstLarge
			firstLarge = digit
		} else if digit > secondLarge {
			secondLarge = digit
		}

		n /= 10
	}

	return firstLarge * secondLarge
}

func main() {
	// test cases 1
	n1 := 31
	fmt.Println(maxProduct(n1))

	// test cases 2
	n2 := 22
	fmt.Println(maxProduct(n2))

	n3 := 124
	fmt.Println(maxProduct(n3))
}
