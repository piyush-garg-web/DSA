class node {
    public:
    int data;
    int row;
    int col;
    int size;

    node (int data,int row,int col,int size) {
        this->data=data;
        this->row=row;
        this->col=col;
        this->size=size;
    }
};

class compare {
    public:
    bool operator()(node*a,node*b) {
        return a->data>b->data;
    } 
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int size=0;
        priority_queue<node*,vector<node*>,compare> pq;
        int n=nums.size();
for (int i=0;i<n;i++) {
    int element=nums[i][0];
    mini=min(mini,element);
    maxi=max(maxi,element);
    size=nums[i].size();
    pq.push(new node(element,i,0,size));
}

int start=mini;
int end=maxi;
int row=-1;
int col=-1;
while (!pq.empty()) {
    node* temp=pq.top();
    pq.pop();
    mini=temp->data;
    size=temp->size;
    row=temp->row;
    col=temp->col;
    if (maxi-mini<end-start || ((mini-maxi==start-end)&& (mini<start))) {
        start=mini;
        end=maxi;
    }

    if (col+1<size) {
        maxi=max(maxi,nums[row][col+1]);
        pq.push(new node(nums[row][col+1],row,col+1,size));
    }

    else {
        break;
    }
}

vector<int> ans;
ans.push_back(start);
ans.push_back(end);
return ans;
        
    }
};