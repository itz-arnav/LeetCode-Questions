class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int n = s.size();
        int m=  g.size();
        n--, m--;
        int ans = 0;
        while(n >= 0 and m>=0){
            if(s[n] >= g[m]){
                ans++;
                n--,m--;
            }
            else{
                m--;
            }
        }
        return ans;
    }
};