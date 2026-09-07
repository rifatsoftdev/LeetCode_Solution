package main

import "fmt"

// Past the function from leetcode here
func checkDivisibility(n int) bool {
	sum := 0
	pro := 1
	m := n

	for n != 0 {
		d := n % 10

		sum += d
		pro *= d

		n /= 10
	}

	return m%(sum+pro) == 0
}

func main() {
	// test cases 1
	fmt.Println(checkDivisibility(99))

	// test cases 2
	fmt.Println(checkDivisibility(23))

}
