class Solution {
public:
    int fact(int n){
        if(n <= 1)
            return 1;
        return n*fact(n-1);
    }
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i<=n; i++){
            s.push_back('0' + i);
        }
        string ans = "";
        
        while(ans.size() < n){
            int sz = ans.size();
            int idx = 0;
            int val = fact(n-1-sz);
            for(int i = 0; i<=n-1-sz; i++){
                if((i+1)*val >= k){
                    idx = i;
                    break;
                }
            }
            ans.push_back(s[idx]);
            s = s.substr(0, idx) + s.substr(idx+1);
            k = k -  idx*val;
        }
        return ans;
        
    }
};