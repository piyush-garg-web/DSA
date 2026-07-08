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
if (head==NULL || head->next==NULL) {
    return head;
}

ListNode* dummy= new ListNode();
dummy->next=head;
ListNode* prev=dummy;
ListNode* curr=head;
while (curr!=NULL) {
    if ((curr->next!=NULL) && (curr->val==curr->next->val)) {
        while ((curr->next!=NULL) && (curr->val==curr->next->val)) {
            ListNode* temp1=curr;
            curr=curr->next;
            temp1->next=NULL;
            delete(temp1);
        }
        ListNode* temp2=curr;
        prev->next=curr->next;
        curr=curr->next;
        temp2->next=NULL;
        delete(temp2);
    } 
    else {
        curr=curr->next;
        prev=prev->next;
    }
}
ListNode* currentHead=dummy->next;
dummy->next=NULL;
delete(dummy);
return currentHead;
    }
};