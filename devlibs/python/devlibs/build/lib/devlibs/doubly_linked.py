from typing import Optional



# Definition for doubly-linked list.
class ListNode:
    def __init__(self, val=0, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev


# List To Doubly LinkedList
def listToDoublyLinkedList(nums: list[int]) -> Optional[ListNode]:
    if not nums:
        return None
    head = ListNode(nums[0])
    curr = head
    for i in range(1, len(nums)):
        new_node = ListNode(nums[i])
        curr.next = new_node
        new_node.prev = curr
        curr = curr.next
    return head


# Print Doubly LinkList
def printDoublyLinkList(head: Optional[ListNode]) -> None:
    curr = head
    result = []
    while curr:
        result.append(str(curr.val))
        curr = curr.next
    print(" <-> ".join(result) if result else "None")

