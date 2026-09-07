package main

import "fmt"

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reorderList(head *ListNode) {
	var arr []int

	curr := head

	for curr != nil {
		arr = append(arr, curr.Val)
		curr = curr.Next
	}

	n := len(arr) - 1
	cnt := 0
	curr = head

	for curr != nil {
		if cnt%2 == 0 {
			curr.Val = arr[cnt/2]
		} else {
			curr.Val = arr[n-(cnt/2)]
		}
		curr = curr.Next
		cnt++
	}

}

func createSinglyLinkedList(values []int) *ListNode {
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

func printSinglyLinkedList(head *ListNode) {
	current := head

	for current != nil {
		fmt.Print(current.Val, " ")
		current = current.Next
	}

	fmt.Println()
}

func main() {

	// test case 1
	list1 := []int{1, 2, 3, 4}
	head1 := createSinglyLinkedList(list1)
	reorderList(head1)
	printSinglyLinkedList(head1)

	// test case 2
	list2 := []int{1, 2, 3, 4, 5}
	head2 := createSinglyLinkedList(list2)
	reorderList(head2)
	printSinglyLinkedList(head2)
}
