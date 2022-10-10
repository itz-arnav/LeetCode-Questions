class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(char c: s){
            mp[c]++;
        }
        int z = 0;
        int ans = 0;
        for(auto [x,y] : mp){
            if(y&1){
                ans += y-1;
                z = 1;
            }
            else
                ans+=y;
        }
        if(z > 0)
            ans+=z;
        return ans;
    }
};