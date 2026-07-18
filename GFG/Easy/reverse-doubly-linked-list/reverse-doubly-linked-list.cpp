class Node {
	public:
	int data;
	Node *next;
	Node *prev;
	
	Node(int val) {
		data = val;
		next = nullptr;
		prev = nullptr;
	}
};

class Solution {
	public:
	Node *reverse(Node *head) {
		
		Node* prev = NULL;
		Node* curr = head;
		
		while (curr != NULL) {
			
			Node* temp = curr->next;
			curr->next = prev;
			curr->prev = temp;
			prev = curr;
			curr = temp;
		}
		
		return prev;
		
	}
};
