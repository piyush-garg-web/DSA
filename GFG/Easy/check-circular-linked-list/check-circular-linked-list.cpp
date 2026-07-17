struct Node
{
	int data;
	struct Node* next;
	
	Node(int x) {
		data = x;
		next = NULL;
	}
	
};

class Solution {
	public:
	bool isCircular(Node *head) {
		
		if (head == NULL) {
			return true;
		}
		
		Node* curr = head;
		
		while (curr != NULL && curr->next != head) {
			
			curr = curr->next;
		}
		
		if (curr == NULL) {
			return false;
		}
		
		else {
			return true;
		}
		
	}
};
