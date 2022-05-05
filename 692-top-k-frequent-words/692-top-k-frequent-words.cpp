class Solution {
public:
    static bool cmp(pair<int, string> a, pair<int, string> b){
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto &s : words){
            mp[s]++;
        }
        vector<pair<int, string>> vp;
        for(auto &x : mp){
            vp.push_back({x.second, x.first});
        }
        sort(vp.begin(), vp.end(), cmp);
        
        vector<string> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};