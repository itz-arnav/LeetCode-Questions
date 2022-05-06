class Solution {
public:
    string removeDuplicates(string s, int k) {
        string temp = "";
        string res = s;
        while(res != temp){
            temp = res;
            res = solve(res,k);
        }
        return res;
    }
    string solve(string s, int k){
        string ans = "";
        int n = s.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            if(ans.size()==0){
                ans.push_back(s[i]);
                count = 1;
            }
            else if(s[i]!=ans.back()){
            ans.push_back(s[i]);
            count = 1;
            }
            else{
                count++;
                ans.push_back(s[i]);
                if(count == k){
                for(int j = k; j>0; j--){
                    ans.pop_back();
                }
                
                
                count = 1;
                }
            }
            
        }
        return ans;
    }
};