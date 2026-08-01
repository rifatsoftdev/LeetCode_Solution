package main

import "fmt"

func maxProfit(prices []int) int {
	minPrice := prices[0]
	maxProfit := 0

	for _, price := range prices {
		if price < minPrice {
			minPrice = price
		} else if price-minPrice > maxProfit {
			maxProfit = price - minPrice
		}
	}

	return maxProfit
}

func main() {
	// test cases 1
	prices := []int{7, 1, 5, 3, 6, 4}
	fmt.Printf("%d\n", maxProfit(prices))

	// test cases 2
	prices2 := []int{7, 6, 4, 3, 1}
	fmt.Printf("%d\n", maxProfit(prices2))
}
