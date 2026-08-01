package main

import "fmt"

// Past the function from leetcode here

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeNodes(head *ListNode) *ListNode {
	var curr *ListNode = head
	var newHead *ListNode = nil
	var newTail *ListNode = nil
	sum := 0

	for curr != nil {
		if curr.Val == 0 {
			if sum > 0 {
				newNode := &ListNode{Val: sum}
				if newHead == nil {
					newHead = newNode
					newTail = newNode
				} else {
					newTail.Next = newNode
					newTail = newNode
				}
				sum = 0
			}
		} else {
			sum += curr.Val
		}
		curr = curr.Next
	}

	return newHead
}

func createSinglyLinkList(values []int) *ListNode {
	if len(values) == 0 {
		return nil
	}

	head := &ListNode{Val: values[0]}
	current := head
	for i := 1; i < len(values); i++ {
		current.Next = &ListNode{Val: values[i]}
		current = current.Next
	}
	return head
}

func printSinglyLinkList(head *ListNode) {
	current := head
	for current != nil {
		if current.Next != nil {
			fmt.Printf("%d -> ", current.Val)
		} else {
			fmt.Printf("%d", current.Val)
		}
		current = current.Next
	}
	fmt.Println()
}

func main() {
	// test cases 1
	head1 := createSinglyLinkList([]int{0, 3, 1, 0, 4, 5, 2, 0})
	result1 := mergeNodes(head1)
	printSinglyLinkList(result1) // Expected output: 4 -> 11

	// test cases 2
	head2 := createSinglyLinkList([]int{0, 1, 0, 3, 0, 2, 2, 0})
	result2 := mergeNodes(head2)
	printSinglyLinkList(result2) // Expected output: 1 -> 3 -> 4

}
