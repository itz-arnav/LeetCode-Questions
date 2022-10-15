class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int> mp,mp2;
        for(char c : s)
            mp[c]++;
        for(char c: t)
            mp2[c]++;
        
        int ans = 0;
        
        for(auto x : mp){
            char c = x.first;
            ans += min(mp2[c],mp[c]);
        }
        return t.size() - ans;
    }
};