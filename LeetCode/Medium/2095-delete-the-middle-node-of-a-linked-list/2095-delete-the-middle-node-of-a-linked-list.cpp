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
    private:
    ListNode* middle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while (fast!=NULL) {
            fast=fast->next;
            if (fast!=NULL) {
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next==NULL) {
            return NULL;
        }
        ListNode* middleNode=middle(head);
        ListNode*head1= head;
        while(head1->next!=middleNode) {
            head1=head1->next;
        }
        head1->next=middleNode->next;
        return head;

    }
};