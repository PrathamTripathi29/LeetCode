class MinStack {
public:
    vector<int> st;
    vector<int> mn;
    MinStack() {
        
    }
    
    void push(int value) {
        int minVal = getMin();
        if(st.empty() || minVal > value){
            minVal = value;
        }
        st.push_back(value);
        mn.push_back(minVal);
    }
    
    void pop() {
        st.pop_back();
        mn.pop_back();
    }
    
    int top() {
        return st.empty() ? -1 : st.back();
    }
    
    int getMin() {
        return mn.empty() ? -1 : mn.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
