package main

import "fmt"

func isBalanced(num string) bool {
	evenSum, oddSum := 0, 0
	for i, ch := range num {
		digit := int(ch - '0')
		if i%2 == 0 {
			evenSum += digit
		} else {
			oddSum += digit
		}
	}
	return evenSum == oddSum
}

func main() {
	// Test case 1
	fmt.Println(isBalanced("1234")) // Expected: false

	// Test case 2
	fmt.Println(isBalanced("24123")) // Expected: true

}
