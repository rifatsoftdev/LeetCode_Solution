package main

// Past the function from leetcode here

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}

	return a
}

func insertGreatestCommonDivisors(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	current := head

	for current != nil && current.Next != nil {
		gcdValue := gcd(current.Val, current.Next.Val)
		newNode := &ListNode{Val: gcdValue}

		newNode.Next = current.Next
		current.Next = newNode
		current = newNode.Next
	}

	return head
}

func main() {
	// test cases 1

	// test cases 2

}
