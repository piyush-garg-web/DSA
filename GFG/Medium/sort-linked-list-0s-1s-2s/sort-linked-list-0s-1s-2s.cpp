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
	Node* segregate(Node* head) {
		
		if (head->next == NULL) {
			return head;
		}
		
		Node * dummyZero = new Node(-1);
		Node * dummyOne = new Node(-1);
		Node * dummyTwo = new Node(-1);
		
		Node* zero = dummyZero;
		Node* one = dummyOne;
		Node* two = dummyTwo;
		
		Node* curr = head;
		
		while (curr != NULL) {
			
			if (curr->data == 0) {
				zero->next = curr;
				zero = zero->next;
			}
			
			else if (curr->data == 1) {
				one->next = curr;
				one = one->next;
			}
			
			else {
				two->next = curr;
				two = two->next;
			}
			
			curr = curr->next;
		}
		
		zero->next = (dummyOne->next) ? (dummyOne->next) : (dummyTwo->next);
		one->next = dummyTwo->next;
		two->next = NULL;
		
		Node* newHead = dummyZero->next;
		
		delete dummyZero;
		delete dummyOne;
		delete dummyTwo;
		
		return newHead;
		
	}
};
