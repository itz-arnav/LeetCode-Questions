class CountIntervals {
public:
    CountIntervals() {
        
    }
    
    map<int, int> m;
    int cnt = 0;
    void add(int left, int right) {
        int add = right - left + 1;
        auto it = m.upper_bound(left);
        if (it != begin(m)) {
            auto p = prev(it);
            if (p->second >= left) {
                left = p->first;
                right = max(right, p->second);
                add = right - p->second;
                m.erase(p);
            }
        }
        while (it != end(m) && it->first <= right) {
            add -= min(right, it->second) - it->first + 1;
            right = max(right, it->second);
            m.erase(it++);
        }
        m[left] = right;
        cnt += add;
    }
    int count() { return cnt; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */