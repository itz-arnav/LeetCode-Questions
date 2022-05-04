class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        
        int ct = 0;
        for(auto &x : mp){
                int key = x.first;
                int val = x.second;
                int y = k - (key);
                    
                if(y == (key) and mp[y] >= 2){
                    ct+=val/2;
                    mp[y] = 0;
                }
                else if(mp.find(y) != mp.end() and mp[y] > 0 and y != (key)){
                    
                    int dec=min(mp[y], val);
                    ct+=dec;
                    mp[y] -= dec;
                    mp[key]-=dec;
                }
                
        }
        return ct;
    }
};