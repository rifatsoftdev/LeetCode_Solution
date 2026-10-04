from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def gcd(self, a: int, b: int) -> int:
        while b:
            a, b = b, a % b
        return a
    
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        current = head

        while current and current.next:
            next_node = current.next

            gcd_value = self.gcd(current.val, next_node.val)

            new_node = ListNode(gcd_value)
            current.next = new_node
            new_node.next = next_node
            current = next_node

        return head


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    # test cases 2
    
    