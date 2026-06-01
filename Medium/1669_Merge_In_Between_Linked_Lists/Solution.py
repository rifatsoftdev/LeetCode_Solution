from typing import List, Optional
from devlibs.singly_linkedlist import ListNode, listToSinglyLinkedList, printSinglyLinkList


class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        i = 0
        prev = None
        curr = list1

        while curr != None and i < a:
            prev = curr
            curr = curr.next
            i += 1

        temp = curr
        while i <= b and temp != None:
            temp = temp.next
            i += 1

        tail = list2
        while tail.next != None:
            tail = tail.next

        if prev != None:
            prev.next = list2
        else:
            list1 = list2

        tail.next = temp

        return list1


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    list1 = listToSinglyLinkedList([0, 1, 2, 3, 4, 5])
    list2 = listToSinglyLinkedList([1000000, 1000001, 1000002])
    a = 3
    b = 4
    result = solution.mergeInBetween(list1, a, b, list2)
    printSinglyLinkList(result)
    
    # test cases 2
    list1 = listToSinglyLinkedList([0, 1, 2, 3, 4, 5, 6])
    list2 = listToSinglyLinkedList([1000000, 1000001, 1000002, 1000003, 1000004])
    a = 2
    b = 5
    result = solution.mergeInBetween(list1, a, b, list2)
    printSinglyLinkList(result)
    
    