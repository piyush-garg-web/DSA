class node {
    public:
    int dist;
    int x;
    int y;
};

class compare {
    public:
    bool operator()(node* a,node*b) {
        return a->dist<b->dist;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<node*,vector<node*>,compare> pq;
        int n=points.size();
        for (int i=0;i<n;i++) {
            node* temp=new node();
            int x=points[i][0];
            int y=points[i][1];
            int distance=x*x + y*y;
            temp->dist=distance;
            temp->x=x;
            temp->y=y;
         pq.push(temp);
         if (pq.size()>k) {
            pq.pop();
         }
        }

vector<int> subans;
        while (!pq.empty()) {
            node* temp=pq.top();
            subans.push_back(temp->x);
            subans.push_back(temp->y);
            ans.push_back(subans);
            subans.clear();
            pq.pop();
        }

        return ans;
        
    }
};