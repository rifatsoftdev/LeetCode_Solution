#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Marge k sorted lists into one sorted list:
    1. Convert each linked list into an array and merge all arrays into one array.
    2. Sort the merged array.
    3. Convert the sorted array back into a linked list.

Time complexity: O(N log N), where N is the total number of nodes across all lists.
Space complexity: O(N), where N is the total number of nodes across all lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/

class Solution {
    void list2array(ListNode* head, vector<int>& arr) {
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for (ListNode* head : lists) {
            list2array(head, arr);
        }

        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        for (int val : arr) {
            temp->next = new ListNode(val);
            temp = temp->next;
        }

        return dummy->next;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    vector<ListNode*> lists1 = {
        new ListNode(1, new ListNode(4, new ListNode(5))),
        new ListNode(1, new ListNode(3, new ListNode(4))),
        new ListNode(2, new ListNode(6))
    };
    ListNode* result1 = solution.mergeKLists(lists1);
    printSinglyLinkList(result1); // Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

    vector<ListNode*> lists2 = {};
    ListNode* result2 = solution.mergeKLists(lists2);
    printSinglyLinkList(result2); // Output: (empty list)

    vector<ListNode*> lists3 = {{}};
    ListNode* result3 = solution.mergeKLists(lists3);
    printSinglyLinkList(result3); // Output: (empty list)
    
    return 0;
}