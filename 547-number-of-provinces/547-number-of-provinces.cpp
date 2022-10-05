class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;
    
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void union_set(int a, int b){
        int s1 = find(a);
        int s2 = find(b);
        if(s1 != s2){
            if(size[s1] < size[s2]){
                swap(s1, s2);
            }
            size[s1] += size[s2];
            parent[s2] = s1;
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = n;
        
        for(int i = 0; i<n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(arr[i][j] == 1){
                    union_set(i,j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; ++i){
            if(parent[i] == i){
                ans++;
            }
        }
        return ans;
    }
};