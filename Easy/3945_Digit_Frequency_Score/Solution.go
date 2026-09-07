package main

import "fmt"

// Past the function from leetcode here
func digitFrequencyScore(n int) int {
	ans := 0

	for n != 0 {
		d := n % 10
		ans += d
		n /= 10
	}

	return ans
}

func main() {
	// test cases 1
	fmt.Println(digitFrequencyScore(122))

	// test cases 2
	fmt.Println(digitFrequencyScore(101))

}
