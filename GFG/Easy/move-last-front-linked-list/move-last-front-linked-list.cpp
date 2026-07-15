class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
};

class Solution {
	public:
	Node *moveToFront(Node *head) {
		
		if (head->next == NULL) {
			return head;
		}
		
		Node* prev = NULL;
		Node* curr = head;
		
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		
		prev->next = NULL;
		
		curr->next = head;
		head = curr;
		
		return head;
		
	}
};
