class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        
        int r1 = s[1] - '0';
        int r2 = s[4] - '0';
        char c1 = s[0];
        char c2 = s[3];
        
        for(char c = c1; c<= c2; ++c){
            for(int i = r1; i<=r2; ++i){
                string res = "";
                res.push_back(c);
                res += to_string(i);
                ans.push_back(res);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};