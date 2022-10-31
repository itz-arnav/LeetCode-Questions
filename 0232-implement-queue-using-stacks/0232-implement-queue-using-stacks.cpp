class MyQueue {
private:
    stack<int> first;
    stack<int> second;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!first.empty()) {
            second.push(first.top());
            first.pop();
        }
        
        second.push(x);
        
        while (!second.empty()) {
            first.push(second.top());
            second.pop();
        }
    }
    
    int pop() {
        int ret;
        ret = first.top();
        first.pop();
        return ret;
    }
    
    int peek() {
        return first.top();
    }
    
    bool empty() {
        return first.empty();
    }
};