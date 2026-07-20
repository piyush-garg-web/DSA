class Node
{
	public:
	int data;
	Node *prev;
	Node *next;
	
	Node(int x)
	{
		data = x;
		prev = nullptr;
		next = nullptr;
	}
};

class Solution {
	public:
	Node *rotateDLL(Node *head, int k) {
		
		int req = 1;
		Node* curr = head;
		
		while (req<k) {
			curr = curr->next;
			req++;
		}
		
		if (curr->next==NULL) {
		    
		    return head;
		}
 		
		Node* newHead = curr->next;
		curr->next = NULL;
		newHead->prev = NULL;
		
		Node* temp = newHead;
		
		while (temp->next != NULL) {
			temp = temp->next;
		}
		
		temp->next = head;
		head->prev = temp;
		
		return newHead;
	}
};
