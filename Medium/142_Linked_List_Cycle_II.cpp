#include <iostream>
#include <vector>
#include <algorithm>
#include "../devlibs/cpphelper.h"

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/


/*
Linked List Cycle II:
1. First, we use the same two-pointer technique to determine if there is a cycle in the linked list. If there is no cycle, we return nullptr.
2. If there is a cycle, we find the meeting point of the slow and fast pointers.
3. To find the start of the cycle, we initialize two pointers: one starting from the head of the list and the other starting from the meeting point. We move both pointers one step at a time until they meet. The point at which they meet will be the start of the cycle.

Time Complexity: O(n) - In the worst case, we may need to traverse the entire list twice (once to find the meeting point and once to find the start of the cycle).
Space Complexity: O(1) - We are using only a constant amount of extra space for the pointers.
*/

class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) 
                return slow;    // meeting point
        }
        
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* meetingPoint = hasCycle(head);
        if (!meetingPoint) return nullptr; 
        
        ListNode* start = head;
        ListNode* meet = meetingPoint;
        
        while (start != meet) {
            start = start->next;
            meet = meet->next;
        }
        
        return start; // cycle start
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}