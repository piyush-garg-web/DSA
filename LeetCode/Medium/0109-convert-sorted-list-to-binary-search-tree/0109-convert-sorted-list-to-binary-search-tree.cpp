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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slowPrevious = NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL) {
            slowPrevious = slow;
            slow = slow->next;
            fast = fast->next;

            if (fast != NULL) {
                fast = fast->next;
            }
        }

        return slowPrevious;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            return new TreeNode(head->val);
        }

        ListNode* middlePrevious = findMiddle(head);
        ListNode* middle = middlePrevious->next;
        TreeNode* root = new TreeNode(middle->val);
        middlePrevious->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(middle->next);
        return root;
    }
};