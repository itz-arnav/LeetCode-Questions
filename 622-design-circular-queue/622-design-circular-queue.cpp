class MyCircularQueue {
public:
    int front = -2, rear = -1;
    int s = 0, cs = 0;
    vector<int> q;
    MyCircularQueue(int k) {
        q.resize(k);
        s = k;
    }
    
    bool enQueue(int value) {
        if(cs == s){
            return false;
        }
        if(cs == 0){
            front = rear = 0;
            q[front] = value;
            cs++;
        }
        else{
            cs++;
            rear++;
            rear%=s;
            q[rear] = value;
        }
        
        return true;
    }
    
    bool deQueue() {
        if(cs == 0)
            return false;
        cs--;
        front++;
        front%=s;
        return true;
    }
    
    int Front() {
        if(cs == 0)
            return -1;
        return q[front];
    }
    
    int Rear() {
        if(cs == 0)
            return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return cs==0;
    }
    
    bool isFull() {
        return cs==s;
    }
};

