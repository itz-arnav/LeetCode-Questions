class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n&1){
            ans.push_back(0);
            n--;
        }
        for(int i = 1; i<=n; i+=2){
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};