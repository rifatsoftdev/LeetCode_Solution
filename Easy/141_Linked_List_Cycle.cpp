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
Linked List Cycle:
1. Use two pointers, slow and fast. Slow moves one step at a time, while fast moves two steps at a time.
2. If there is a cycle, the fast pointer will eventually meet the slow pointer.
3. If there is no cycle, the fast pointer will reach the end of the list (nullptr) without meeting the slow pointer.

Time Complexity: O(n) - In the worst case, we may need to traverse the entire list once.
Space Complexity: O(1) - We are using only a constant amount of extra space for the two pointers.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}