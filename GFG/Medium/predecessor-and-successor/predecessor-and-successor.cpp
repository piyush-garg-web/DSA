class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

class Solution {
	public:
	vector<Node*> findPreSuc(Node* root, int key) {
		
		vector<Node*> ans;
		
		Node* pre = NULL;
		Node* succ = NULL;
		Node* curr = root;
		
		while (curr != NULL) {
			
			if (curr->data == key) {
				
				if (curr->left) {
					Node* temp = curr->left;
					while (temp->right) {
						temp = temp->right;
					}
					
					pre = temp;
				}
				
				if (curr->right) {
					Node* temp = curr->right;
					while (temp->left) {
						temp = temp->left;
					}
					
					succ = temp;
				}
				
				break;
				
			}
			
			else if (curr->data<key) {
				pre = curr;
				curr = curr->right;
			}
			
			else {
				succ = curr;
				curr = curr->left;
			}
		}
		
		ans.push_back(pre);
		ans.push_back(succ);
		
		return ans;
		
	}
};
