from typing import List, Optional
from devlibs.singly_linkedlist import ListNode


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head

        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        return prev

    def pairSum(self, head: Optional[ListNode]) -> int:
        slow, fast = head, head
        
        # Find the middle of the linked list
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        # Reverse the second half
        second_half = self.reverseList(slow)
        first_half = head
        
        max_sum = 0
        # Calculate twin sums
        while second_half:
            max_sum = max(max_sum, first_half.val + second_half.val)
            first_half = first_half.next
            second_half = second_half.next
            
        return max_sum
                


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1 = ListNode(5, ListNode(4, ListNode(2, ListNode(1))))
    print(solution.pairSum(head1))  # Output: 6

    # test cases 2
    head2 = ListNode(4, ListNode(2, ListNode(2, ListNode(3))))
    print(solution.pairSum(head2))  # Output: 7

    # test cases 3
    head3 = ListNode(1, ListNode(100000))
    print(solution.pairSum(head3))  # Output: 100001
    
    
    
    