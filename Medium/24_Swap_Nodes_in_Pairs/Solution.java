


public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode temp = dummy;

        while (temp.next != null && temp.next.next != null) {
            ListNode first = temp.next;
            ListNode second = first.next;

            // Swap
            first.next = second.next;
            second.next = first;
            temp.next = second;

            // Move to the next pair
            temp = first;
        }

        return dummy.next;
    }

    private static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val);
            if (current.next != null) {
                System.out.print(" -> ");
            }
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        ListNode head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        ListNode result1 = solution.swapPairs(head1);
        printList(result1); // Expected output: 2 -> 1 -> 4 -> 3


        // test cases 2
        ListNode head2 = new ListNode(1);
        ListNode result2 = solution.swapPairs(head2);
        printList(result2); // Expected output: 1

        // test cases 3
        ListNode head3 = null;
        ListNode result3 = solution.swapPairs(head3);
        printList(result3); // Expected output: (empty list)

        // test cases 4
        ListNode head4 = new ListNode(1, new ListNode(2, new ListNode(3)));
        ListNode result4 = solution.swapPairs(head4);
        printList(result4); // Expected output: 2 -> 1 -> 3
    }
}


// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
