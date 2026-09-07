package main

import "fmt"

// Past the function from leetcode here
func smallestNumber(n int, t int) int {
	current := n

	for {
		product := 1
		temp := current

		for temp > 0 {
			digit := temp % 10

			if digit == 0 {
				product = 0
				break
			}

			product *= digit
			temp /= 10
		}

		if product%t == 0 {
			return current
		}
		current++
	}
}

func main() {
	// test cases 1
	fmt.Println(smallestNumber(10, 2)) // Expected output: 10

	// test cases 2
	fmt.Println(smallestNumber(15, 3)) // Expected output: 16

}
