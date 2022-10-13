class Solution {
public:
    int garbageCollection(vector<string>& arr, vector<int>& travel) {
        int time = 0, trav = 0;
        
        bool g = 0, p = 0, m = 0;
        
        for(auto x : travel)
            trav += x;
        
        int n = arr.size();
        for(int i = n-1; i>=0; --i){
            if(i < n-1)
            trav -= travel[i];
            int mp[100] = {0};
            for(auto c : arr[i])
                mp[c]++;
            
            if(mp['G'] > 0){
                time += mp['G'];
                if(g == 0){
                    g = 1;
                    time += trav;
                }
            }
            if(mp['P'] > 0){
                time += mp['P'];
                if(p == 0){
                    p = 1;
                    time += trav;
                }
            }
            if(mp['M'] > 0){
                time += mp['M'];
                if(m == 0){
                    m = 1;
                    time += trav;
                }
            }
        }
        return time;
    }
};