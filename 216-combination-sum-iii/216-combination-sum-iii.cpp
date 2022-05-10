class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i, int j, int k, int cs, int n, vector<int>&arr){
        if(cs == n and j == k){
            ans.push_back(arr);
            return;
        }
        if(i > 9)
            return;
        if(j > k)
            return;
        if(cs > n)
            return;
        
        arr.push_back(i);
        solve(i+1, j+1, k, cs + i, n, arr);
        arr.pop_back();
        solve(i+1, j, k, cs, n, arr);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        solve(1,0,k,0,n,arr);
        return ans;
    }
};