#include<stack>
class Solution {
    private:
    void nextSmallerElement(vector<int>& s,vector<int> &heights,int n) {
stack<int> st;
st.push(-1);
for (int i=n-1;i>=0;i--) {
   while ((st.top()!=-1) && (heights[st.top()]>=heights[i])) {
    st.pop();
   }
   s[i]=st.top();
   st.push(i);
    }
}
    
    void prevSmallerElement(vector<int>& l,vector<int> &heights,int n) {
stack<int> st;
st.push(-1);
for (int i=0;i<n;i++) {
   while ((st.top()!=-1) && (heights[st.top()]>=heights[i])) {
    st.pop();
   }
   l[i]=st.top();
   st.push(i);
    }
}
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> s(n);
        vector<int> l(n);
        nextSmallerElement(s,heights,n);
        prevSmallerElement(l,heights,n);
        int maxArea=INT_MIN;
        int prev;
        int next;
        for (int i=0;i<n;i++) {
prev=l[i];
next=s[i];
if (next==-1) {
    next=n;
}
maxArea=max(heights[i]*(next-prev-1),maxArea);
        }
return maxArea;
    }
};