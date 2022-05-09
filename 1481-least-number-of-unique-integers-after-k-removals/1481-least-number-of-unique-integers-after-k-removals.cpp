class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto &x : arr)
            mp[x]++;
        
        vector<pair<int,int>> vp;
        for(auto &x : mp){
            vp.push_back({x.second, x.first});
        }
        sort(vp.begin(), vp.end());
        int x = 0;
        for(; x < vp.size(); x++){
            if(vp[x].first > k)
                break;
            else{
                k-=vp[x].first;
            }
        }
        return vp.size()-x;
    }
};