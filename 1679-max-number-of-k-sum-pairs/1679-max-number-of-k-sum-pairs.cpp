class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        int ct = 0;
        for(auto &x : mp){
            while(mp[x.first] > 0){
                int y = k - (x.first);
                if(y == (x.first)){
                    if(mp[y] > 1){
                        mp[y]-=2;
                        
                        ct++;
                    }
                    else
                        break;
                }
                else if(mp[y] > 0){
                    mp[y]--;
                    mp[x.first]--;
                    ct++;
                }
                else{
                    break;
                }
            }
        }
        return ct;
    }
};