class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i<n; ++i){
            prefix[i] = arr[i];
            if(i > 0)
                prefix[i]^= prefix[i-1];
        }
        vector<int> ans;
        for(auto x : q){
            if(x[0] == 0){
                ans.push_back(prefix[x[1]]);
            }
            else{
                ans.push_back(prefix[x[1]] ^ prefix[x[0] - 1]);
            }
        }
        return ans;
    }
};