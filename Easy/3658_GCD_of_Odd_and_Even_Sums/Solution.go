package main

import "fmt"

// Past the function from leetcode here
func gcdOfOddEvenSums(n int) int {
	var oddSum int = 0
	var evenSum int = 0

	for i := 1; i <= n*2; i += 2 {
		oddSum += i
	}

	for i := 2; i <= n*2; i += 2 {
		evenSum += i
	}

	for evenSum != 0 {
		oddSum, evenSum = evenSum, oddSum%evenSum
	}

	return oddSum
}

func main() {
	// test cases 1
	fmt.Println(gcdOfOddEvenSums(4))

	// test cases 2
	fmt.Println(gcdOfOddEvenSums(5))

}
