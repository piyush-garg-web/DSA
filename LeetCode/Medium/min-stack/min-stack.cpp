#include <stack>

class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else if (val >= mini) {
            st.push(val);
        } else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }

        long long n = st.top();
        st.pop();

        if (n < mini) {
            mini = 2 * mini - n;
        }
    }

    int top() {
        if (st.empty()) {
            return -1;
        }

        if (st.top() >= mini) {
            return (int)st.top();
        }

        return (int)mini;
    }

    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */