


public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        int len = 0;
        ListNode curr = head;

        while (curr != null) {
            curr = curr.next;
            len++;
        }

        int rotate = k % len;

        if (rotate == 0){
            return head;
        }
        
        ListNode newTail = head;
        for (int i = 1; i < len - rotate; i++) {
            newTail = newTail.next;
        }

        ListNode newHead = newTail.next;
        newTail.next = null;
        ListNode temp = newHead;

        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = head;

        return newHead;
    }

    void printSinglyLinkList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        ListNode head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        int k1 = 2;
        ListNode result1 = solution.rotateRight(head1, k1);
        solution.printSinglyLinkList(result1); // Expected output: 4 -> 5 -> 1 -> 2 -> 3

        // test cases 2
        ListNode head2 = new ListNode(0, new ListNode(1, new ListNode(2)));
        int k2 = 4;
        ListNode result2 = solution.rotateRight(head2, k2);
        solution.printSinglyLinkList(result2); // Expected output: 2 -> 0 -> 1
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