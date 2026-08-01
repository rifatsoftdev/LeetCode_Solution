package main

import "fmt"

// Past the function from leetcode here
func findRestaurant(list1 []string, list2 []string) []string {
	mp := make(map[string]int)

	for i, s := range list1 {
		mp[s] = i
	}

	minSum := len(list1) + len(list2)
	ans := []string{}

	for i, s := range list2 {
		if idx, ok := mp[s]; ok {
			indexSum := idx + i

			if indexSum < minSum {
				minSum = indexSum
				ans = []string{s}
			} else if indexSum == minSum {
				ans = append(ans, s)
			}
		}
	}

	return ans
}

func main() {
	// test cases 1
	list11 := []string{"Shogun", "Tapioca Express", "Burger King", "KFC"}
	list12 := []string{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"}
	ans1 := findRestaurant(list11, list12)
	fmt.Println(ans1)

	// test cases 2
	list21 := []string{"Shogun", "Tapioca Express", "Burger King", "KFC"}
	list22 := []string{"KFC", "Shogun", "Burger King"}
	ans2 := findRestaurant(list21, list22)
	fmt.Println(ans2)

	// test cases 3
	list31 := []string{"happy", "sad", "good"}
	list32 := []string{"sad", "happy", "good"}
	ans3 := findRestaurant(list31, list32)
	fmt.Println(ans3)

}
