class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty())
        {
        mini=value;
        st.push(value);
        }
        else{
            if(value>=mini) st.push(value);
            else{
                st.push(2LL*value-mini);
                mini=value;
            }
        }   
    }
    
    void pop() {
        if(st.empty())return;
        if(st.top()<mini)mini=2*mini-st.top();
        st.pop();
    }
    
    int top() {
      if(st.top()<mini)return (int)mini;
      return  (int)st.top();
    }
    
    int getMin() {
      return  (int)mini;
    }
};

/**
 * Your miniStack object will be instantiated and called as such:
 * miniStack* obj = new miniStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getmini();
 */