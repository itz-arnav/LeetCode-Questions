class Solution {
public:
    int minFlips(string s) {
        int ans = 0;
        bool first = false;
        int n= s.size();
        for(int i = n-1; i>=0; --i){
            if(s[i] == '1'){
                while(i >= 0 and s[i] == '1'){
                    i--;
                }
                i++;
                if(first)
                    ans+=2;
                else{
                    ans++;
                    first = true;
                }
            }
            else{
                first = true;
            }
        }
        return ans;
    }
};