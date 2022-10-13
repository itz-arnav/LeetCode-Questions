class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> mp;
        for(auto x : logs){
            mp[x[0]].insert(x[1]);
        }
        vector<int> ans(k);
        unordered_map<int,int> res;
        for(auto x : mp)
            res[x.second.size()]++;
        for(int i = 1; i<=k; ++i){
            ans[i-1] = res[i];
        }
        return ans;
    }
};