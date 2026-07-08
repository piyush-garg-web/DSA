class Solution {
	public:
	void rearrange(vector<int> &arr) {
		vector<int> p;
		vector<int> n;
		
		for (int i = 0; i<arr.size(); i++) {
			if (arr[i] >= 0) {
				p.push_back(arr[i]);
			}
			
			else {
				n.push_back(arr[i]);
			}
		}
		
		int i = 0;
		int j = 0;
		int k = 0;
		
		while (i<p.size() && j<n.size()) {
			arr[k] = p[i];
			i++;
			k++;
			arr[k] = n[j];
			j++;
			k++;
		}
		
		while (i<p.size()) {
		    arr[k]=p[i];
		    i++;
		    k++;
		}
		
		while (j<n.size()) {
		    arr[k]=n[j];
		    j++;
		    k++;
		}
	}
};
