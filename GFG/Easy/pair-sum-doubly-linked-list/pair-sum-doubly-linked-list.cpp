class Node
{
	public:
	int data;
	Node *next, *prev;
	Node(int val) : data(val), next(NULL), prev(NULL)
	{
	}
};

class Solution {
	public:
	vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
		
		vector<pair<int, int>> ans;
		
		Node* start = head;
		Node* end = head;
		
		while (end->next != NULL) {
			end = end->next;
		}
		
		while (start != end && start->prev != end) {
			
			int sum = start->data + end->data;
			
			if (sum == target) {
				ans.push_back({start->data, end->data});
				start = start->next;
				end = end->prev;
			}
			
			else if (sum<target) {
				
				start = start->next;
			}
			
			else {
				
				end = end->prev;
			}
		}
		
		return ans;
		
	}
};
