class MyQueue {
    int arr[1000];
    int start,end,currentsize,capacity;
public:
    MyQueue() {
        start=-1;
        end=-1;
        currentsize=0;
        capacity=1000;
    }
    
    void push(int x) {
        if(currentsize==capacity)return ;
        if(currentsize==0){
            start=0;
            end=0;
        }else{
            end=(end+1)%capacity;
        }
        arr[end]=x;
        currentsize++;
    }
    
    int pop() {
        int val=arr[start];
        if(currentsize==1){
            start=-1;
            end=-1;
        }else{
            start=(start+1)%capacity;
        }
        currentsize--;
        return val;
    }
    
    int peek() {
        return arr[start];
    }
    
    bool empty() {
        return currentsize==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */