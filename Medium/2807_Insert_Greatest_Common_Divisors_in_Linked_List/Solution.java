import java.util.*;


public class Solution {
    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode current = head;

        while (current != null && current.next != null) {
            int gcdValue = gcd(current.val, current.next.val);

            ListNode newNode = new ListNode(gcdValue);

            newNode.next = current.next;
            current.next = newNode;
            current = newNode.next;
        }

        return head;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        // test cases 2
        
        
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
