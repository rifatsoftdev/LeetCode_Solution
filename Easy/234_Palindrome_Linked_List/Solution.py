from typing import List, Optional
from devlibs.singly_linkedlist import ListNode


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head

        while (fast != None and fast.next != None):
            slow = slow.next
            fast = fast.next.next
        
        prev = None
        curr = slow
        
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        

        while (prev):
            if (head.val != prev.val):
                return False
            prev = prev.next
            head = head.next
        
        return True


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1 = ListNode(1, ListNode(2, ListNode(2, ListNode(1))))
    print(solution.isPalindrome(head1))  # Expected: True

    # test cases 2
    head2 = ListNode(1, ListNode(2))
    print(solution.isPalindrome(head2))  # Expected: False
    
    
    