

public class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode curr = head;
        ListNode newHead = new ListNode(0);
        ListNode newCurr = newHead;

        int sum = 0;

        while (curr != null) {
            if (curr.val == 0) {
                if (sum > 0) {
                    newCurr.next = new ListNode(sum);
                    newCurr = newCurr.next;
                    sum = 0;
                }
            } else {
                sum += curr.val;
            }

            curr = curr.next;
        }

        return newHead.next;
    }

    private static ListNode createSinglyLinkList(int[] values) {
        ListNode dummyHead = new ListNode(0);
        ListNode current = dummyHead;

        for (int value : values) {
            current.next = new ListNode(value);
            current = current.next;
        }

        return dummyHead.next;
    }

    private static void printSinglyLinkList(ListNode head) {
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
        ListNode head1 = createSinglyLinkList(new int[]{0,3,1,0,4,5,2,0});
        ListNode result1 = solution.mergeNodes(head1);
        printSinglyLinkList(result1); // Expected output: 4 -> 11

        // test cases 2
        ListNode head2 = createSinglyLinkList(new int[]{0,1,0,3,0,2,2,0});
        ListNode result2 = solution.mergeNodes(head2);
        printSinglyLinkList(result2); // Expected output: 1 -> 3 -> 4
        
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
