struct Node
{
	int data;
	struct Node *next;
	
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class Solution {
	public:
	pair<Node *, Node *> splitList(struct Node *head) {
		
		if (head == NULL) {
			return {NULL, NULL};
		}
		
		if (head->next == head) {
			return {head, head};
		}
		
		Node* slow = head;
		Node* fast = head;
		
		while (fast->next != head && fast->next->next != head) {
			
			slow = slow->next;
			fast = fast->next->next;
		}
		
		if (fast->next != head) {
			fast = fast->next;
		}
		
		Node* head1 = head;
		Node* head2 = slow->next;
		
		slow->next = head1;
		fast->next = head2;
		
		return {head1, head2};
		
	}
};
