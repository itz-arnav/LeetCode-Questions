class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp, mp2;
        for(auto &x : arr){
            mp[x]++;
        }
        for(auto &x : mp){
            if(mp2.find(x.second) != mp2.end())
                return false;
            
            mp2[x.second]++;
        }
        return true;
    }
};