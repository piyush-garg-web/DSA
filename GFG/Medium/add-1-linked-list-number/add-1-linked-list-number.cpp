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
	Node* reverse(Node*head) {
		
		Node*prev = NULL;
		Node* curr = head;
		
		while (curr != NULL) {
			Node*temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		
		return prev;
	}
	
	public:
	Node* addOne(Node* head) {
		
		head = reverse(head);
		
		Node*curr = head;
		int carry = 1;
		
		while (curr != NULL && carry) {
			
			int sum = curr->data + carry;
			curr->data = sum%10;
			carry = sum/10;
			
			if (curr->next == NULL && carry) {
				curr->next = new Node(carry);
				carry = 0;
			}
			
			curr = curr->next;
		}
		
		return reverse(head);
		
	}
};
