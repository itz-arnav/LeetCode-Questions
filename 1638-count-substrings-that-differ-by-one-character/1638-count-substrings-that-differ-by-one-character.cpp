class Solution {
public:
    int countSubstrings(string s, string t) {
        vector<string> a[102];
        vector<string> b[102];
        for(int i = 0; i<s.size(); ++i){
            string curr = "";
            for(int j = i; j<s.size(); ++j){
                curr.push_back(s[j]);
                a[j-i+1].push_back(curr);
            }
        }
        for(int i = 0; i<t.size(); ++i){
            string curr = "";
            for(int j = i; j<t.size(); ++j){
                curr.push_back(t[j]);
                b[j-i+1].push_back(curr);
            }
        }
        
        int ans = 0;
        for(int i = 1; i<=100; ++i){
            if(a[i].size() == 0 or b[i].size() == 0)
                continue;
            for(int j = 0; j<a[i].size(); ++j){
                for(int k = 0; k<b[i].size(); ++k){
                    int ct = 0;
                    for(int l = 0; l<i; ++l){
                        if(a[i][j][l] != b[i][k][l])
                            ct++;
                    }
                    if(ct == 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};