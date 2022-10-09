class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        for(string s : words){
            mp[s]++;
        }
        int ans = 0;
        for(auto x : words){
            if(mp[x] == 0)
                continue;
            string rev = x;
            reverse(x.begin(), x.end());
            if(x == rev){
                ans += 4*(mp[x]/2);
                mp[x]%=2;
            }
            else{
                ans += 4*min(mp[x], mp[rev]);
                mp[x] = 0;
                mp[rev] = 0;
            }
        }
        for(auto x : words){
            string rev = x;
            reverse(x.begin(), x.end());
            if(x == rev and mp[x] > 0){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};