class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    /*
        1) store first half in maxh, second half in minh
        2) maxh can have 1 element more than minh
    */
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if(minh.size()>maxh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    double findMedian() {
        if(maxh.size()==minh.size()) return (maxh.top()+minh.top())/2.0;
        return maxh.top();
    }
};