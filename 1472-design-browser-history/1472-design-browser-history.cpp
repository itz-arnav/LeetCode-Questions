class BrowserHistory {
public:
    vector<string> arr;
    int sz = 0;
    int curr = -1;
    BrowserHistory(string homepage) {
        arr.resize(200);
        sz=1;
        curr = 0;
        arr[curr] = homepage;
    }
    
    void visit(string url) {
        arr[++curr] = url;
        sz = curr+1;
        
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return arr[curr];
    }
    
    string forward(int steps) {
        curr = min(sz-1, steps+curr);
        return arr[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */