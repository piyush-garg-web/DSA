class Node {
	int data;
	Node *next;
	
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class Solution {
	public:
	Node* deleteNode(Node* head, int key) {
		
		if (head == NULL) {
			return NULL;
		}
		
		if (head->next == head) {
			
			if (head->data == key) {
				
				delete head;
				return NULL;
			}
			
			return head;
			
		}
		
		if (head->data == key) {
			
			Node* temp1 = head;
			Node* temp2 = head->next;
			while (temp1->next != head) {
				temp1 = temp1->next;
			}
			
			temp1->next = temp2;
			delete head;
			return temp2;
			
		}
		
		Node* prev = head;
		Node* curr = head->next;
		
		while (curr != head) {
			
			if (curr->data == key) {
				prev->next = curr->next;
				delete curr;
				return head;
			}
			
			prev = curr;
			curr = curr->next;
		}
		
		return head;
		
	}
};
