class Node {
	public:
	int data;
	Node* next;
	Node* bottom;
	
	Node(int x) {
		data = x;
		next = nullptr;
		bottom = nullptr;
	}
}; 

class Solution {
	private:
	
	Node* merge(Node* head1, Node* head2) {
		
		Node* dummy = new Node(-1);
		Node* tail = dummy;
		
		while (head1 != NULL && head2 != NULL) {
			if (head1->data<head2->data) {
				tail->bottom = head1;
				tail = tail->bottom;
				tail->next = NULL;
				head1 = head1->bottom;
			}
			
			else {
				
				tail->bottom = head2;
				tail = tail->bottom;
				tail->next = NULL;
				head2 = head2->bottom;
			}
			
		}
		
		if (head1 != NULL) {
			tail->bottom = head1;
		}
		
		if (head2 != NULL) {
			tail->bottom = head2;
		}
		
		return dummy->bottom;
	}
	
	public:
	Node *flatten(Node *root) {
		
		if (root == NULL || root->next == NULL) {
			return root;
		}
		
		Node* mergedHead = flatten(root->next);
		return merge(root, mergedHead);
		
	}
};
