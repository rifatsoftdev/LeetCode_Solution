package main

import "fmt"

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{Val: 0}
	dummy.Next = head

	temp := dummy

	for temp.Next != nil && temp.Next.Next != nil {
		first := temp.Next
		second := first.Next

		// Swap
		first.Next = second.Next
		second.Next = first
		temp.Next = second

		// Move to the next pair
		temp = first
	}

	return dummy.Next
}

func printList(head *ListNode) {
	current := head
	for current != nil {
		fmt.Print(current.Val)
		if current.Next != nil {
			fmt.Print(" -> ")
		}
		current = current.Next
	}
	fmt.Println()
}

func main() {
	// test cases 1
	head1 := &ListNode{
		Val: 1,
		Next: &ListNode{
			Val: 2,
			Next: &ListNode{
				Val:  3,
				Next: &ListNode{Val: 4},
			},
		},
	}
	result1 := swapPairs(head1)
	printList(result1) // 2 -> 1 -> 4 -> 3

	// test cases 2
	head2 := &ListNode{Val: 1}
	result2 := swapPairs(head2)
	printList(result2) // 1

	// test cases 3
	var head3 *ListNode = nil
	result3 := swapPairs(head3)
	printList(result3) // (empty)

	// test cases 4
	head4 := &ListNode{
		Val: 1,
		Next: &ListNode{
			Val:  2,
			Next: &ListNode{Val: 3},
		},
	}
	result4 := swapPairs(head4)
	printList(result4) // 2 -> 1 -> 3
}
