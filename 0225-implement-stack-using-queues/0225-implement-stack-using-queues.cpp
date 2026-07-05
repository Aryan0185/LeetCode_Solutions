class MyStack {
    int arr[1000]; 
    int topindex=-1;
public:
    MyStack() {
      int index=-1;
    }
    
    void push(int x) {
       topindex++;
       arr[topindex]=x; 
    }
    
    int pop() {
        int val=arr[topindex];
        topindex--;
        return val;
    }
    
    int top() {
        return arr[topindex];
    }
    
    bool empty() {
        return topindex==-1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */