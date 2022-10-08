class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int x) {
        int n= arr.size();
        vector<bool> ans(n, false);
        int maxx = 0;
        for(auto c : arr){
            maxx = max(maxx, c);
        }
        for(int i = 0; i<n; ++i){
            if(x + arr[i] >= maxx){
                ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }
        return ans;
    }
};