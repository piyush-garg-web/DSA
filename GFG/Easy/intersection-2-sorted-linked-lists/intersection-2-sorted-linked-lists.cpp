struct Node
{
	int data;
	Node *next;
	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

class Solution {
	public:
	Node* findIntersection(Node* head1, Node* head2) {
		
		Node* dummy = new Node (-1);
		Node* tail = dummy;
		Node* curr1 = head1;
		Node* curr2 = head2;
		
		while (curr1 != NULL && curr2 != NULL) {
			
			if (curr1->data == curr2->data) {
				tail->next = new Node(curr1->data);
				tail = tail->next;
				curr1 = curr1->next;
				curr2 = curr2->next;
				
			}
			
			else if (curr1->data<curr2->data) {
				curr1 = curr1->next;
			}
			
			else {
				curr2 = curr2->next;
			}
		}
		
		return dummy->next;
		
	}
};
