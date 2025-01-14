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
    ListNode* deleteDuplicates(ListNode* head) {
        // Sentinel Node to stay at start of list
        ListNode* sentinelHead = new ListNode(0, head);
        // Prev to keep track of where to point next
        ListNode* prev = sentinelHead;

        while(head) {
            bool deletedNodes = false;
            // While to remove duplicates
            while(head->next && head->val == head->next->val) {
                deletedNodes  = true;
                head = head->next;
            }

            // if we deleted nodes, point to next of the head
            // because head is also a duplicate
            if(deletedNodes) {
                prev->next = head->next;
            }
            // Else just move to the next ptr
            else {
                prev = prev->next;
            }

            head = head->next;
        }

        return sentinelHead->next;
    }
};