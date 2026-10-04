package main

import "fmt"

// Past the function from leetcode here
func buyChoco(prices []int, money int) int {
	firstMin := 100
	secondMin := 100

	for _, price := range prices {
		if price < firstMin {
			secondMin = firstMin
			firstMin = price
		} else if price < secondMin {
			secondMin = price
		}
	}

	cost := firstMin + secondMin

	if cost <= money {
		return money - cost
	}

	return money
}

func main() {
	// test case 1
	prices1 := []int{1, 2, 2}
	money1 := 3
	fmt.Println(buyChoco(prices1, money1))

	// test case 2
	prices2 := []int{3, 2, 3}
	money2 := 3
	fmt.Println(buyChoco(prices2, money2))

}
