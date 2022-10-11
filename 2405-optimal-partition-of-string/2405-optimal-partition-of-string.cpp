class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        int ans = 1;
        for(char c: s){
            mp[c]++;
            if(mp[c] > 1){
                ans++;
                mp.clear();
                mp[c] = 1;
            }
        }
        return ans;
    }
};