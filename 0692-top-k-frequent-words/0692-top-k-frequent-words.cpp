class Solution {
public:
    static bool cmp(pair<string,int> &a, pair<string,int> &b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        
        for(auto &x : words)
            mp[x]++;
        
        vector<pair<string, int>> arr;
        
        for(auto &x : mp){
            arr.push_back({x.first, x.second});
        }
        
        sort(arr.begin(), arr.end(), cmp);
        vector<string> ans;
        for(int i = 0; i<k; ++i){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};