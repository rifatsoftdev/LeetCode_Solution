#include "../devlibs/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/* ================================================================================
Solution 1:

Convert Binary Number in a Linked List to Integer:
    1. Traverse the linked list from head to tail to collect the binary digits.
    2. Store the digits in a string or process them directly to calculate the decimal value.
    3. To convert from binary to decimal, iterate through the digits and multiply the current total by 2 before adding the next bit (or use powers of 2).
    4. Return the resulting decimal integer.

Time Complexity: O(n), where n is the number of nodes in the linked list.
Space Complexity: O(1) if processed on the fly, or O(n) if storing the bits in a string.
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
public:
    int getDecimalValue(ListNode* head) {
        string binary = "";
        while (head != NULL) {
            binary += to_string(head->val);
            head = head->next;
        }

        int decimal = 0;
        int power = 0;

        for (int i = binary.size()-1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += pow(2, power);
            }
            power++;
        }

        return decimal;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    

    return 0;
}