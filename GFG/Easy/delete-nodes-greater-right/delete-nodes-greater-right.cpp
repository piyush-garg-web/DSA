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
	private:
	Node * reverse (Node* head) {
		Node* prev = NULL;
		Node* curr = head;
		
		while (curr != NULL) {
			
			Node* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		
		return prev;
	}
	public:
	Node *compute(Node *head) {
		
		if (head->next == NULL) {
			return head;
		}
		
		head = reverse(head);
		
		Node* temp = head;
		int maxi = temp->data;
		
		while (temp != NULL && temp->next != NULL) {
			
			if (temp->next->data<maxi) {
				temp->next = temp->next->next;
			}
			
			else {
				temp = temp->next;
				maxi = temp->data;
			}
		}
		
		return reverse(head);
		
	}
};
