/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    ListNode* isCycle(ListNode* head) {
        if (head==NULL || head->next==NULL) {
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL) {
            fast=fast->next;
            if (fast!=NULL) {
                fast=fast->next;
            }
            slow=slow->next;
            if (fast==slow) {
                return slow;
            }
        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* ptr=isCycle(head);
        if (ptr==NULL) {
            return NULL;
        }
        ListNode* start=head;
        while (start!=ptr) {
            start=start->next;
            ptr=ptr->next;
        }
        return start;
    }
};