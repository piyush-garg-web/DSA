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
    void insertAtTail(ListNode* &newHead, ListNode* &newTail,int digit) {
        ListNode* newNode=new ListNode(digit);
        if (newHead==NULL) {
newHead=newNode;
newTail=newNode;
return;
        }
        newTail->next=newNode;
        newTail=newNode;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1;
        ListNode* h2=l2;
        int sum=0;
        int carry=0;
        int digit;
        ListNode* newHead=NULL;
        ListNode* newTail=NULL;
        int val1;
        int val2;
        while (h1!=NULL || h2!=NULL || carry!=0) {
            if(h1!=NULL) {
                val1=h1->val;
            }
            else {
val1=0;
            }
              if(h2!=NULL) {
                val2=h2->val;
            }
            else {
val2=0;
            }
sum=val1+val2+carry;
digit=sum%10;
insertAtTail(newHead,newTail,digit);
carry=sum/10;
if (h1!=NULL) {
h1=h1->next;
}

if (h2!=NULL) {
h2=h2->next;
}
        }
        return newHead;
    }
};