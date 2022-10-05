class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;
    
    int find_set(int x){
        if(parent.find(x) == parent.end())
            return -1;
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }
    
    void union_set(int a, int b){
        int s1 = find_set(a);
        int s2 = find_set(b);
        if(s1 == s2)
            return;
        if(s2 > s1)
            swap(s1, s2);
        
        size[s1] += size[s2];
        parent[s2] = s1;
    }
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> nums(arr.begin(),arr.end());
        for(auto x : nums){
            parent[x] = x;
            size[x] = 1;
        }
        
        for(auto x : nums){
            if(find_set(x-1) != -1){
                union_set(x-1, x);
            }
            if(find_set(x+1) != -1)
            {
                union_set(x, x+1);
            }
        }
        int best = 0;
        for(auto x : size){
            best = max(best, x.second);
        }
        return best;
    }
};