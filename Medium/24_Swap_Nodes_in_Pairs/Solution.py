from typing import List, Optional
from devlibs.singly_linkedlist import ListNode, listToSinglyLinkedList, printSinglyLinkList


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head

        while ((temp is not None) and (temp.next is not None)):
            # Swap values of current pair
            val0 = temp.val
            temp.val = temp.next.val
            temp.next.val = val0
            
            temp = temp.next.next
            
        return head



if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1 = listToSinglyLinkedList([1,2,3,4])
    result1 = solution.swapPairs(head1)
    printSinglyLinkList(result1)

    # test cases 2
    head2 = listToSinglyLinkedList([])
    result2 = solution.swapPairs(head2)
    printSinglyLinkList(result2)
    
    # test cases 3
    head3 = listToSinglyLinkedList([1])
    result3 = solution.swapPairs(head3)
    printSinglyLinkList(result3)

    # test cases 4
    head4 = listToSinglyLinkedList([1,2,3])
    result4 = solution.swapPairs(head4)
    printSinglyLinkList(result4)
    