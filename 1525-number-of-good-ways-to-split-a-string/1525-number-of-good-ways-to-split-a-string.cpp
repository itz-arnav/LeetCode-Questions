class Solution {
public:
    int numSplits(string s) {
        int n =  s.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        map<char,int> mp;
        for(int i = 0; i<n; ++i){
            mp[s[i]]++;
            prefix[i] = mp.size();
        }
        mp.clear();
        for(int i = n-1; i>=0; --i){
            mp[s[i]]++;
            suffix[i] = mp.size();
        }
        
        int ans = 0;
        for(int i = 0; i<n-1; ++i){
            if(prefix[i] == suffix[i+1])
                ans++;
        }
        return ans;
    }
};