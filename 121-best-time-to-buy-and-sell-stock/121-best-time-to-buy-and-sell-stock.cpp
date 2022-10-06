class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxx = 0, curr = arr[0];
        int n = arr.size();
        for(int i = 1; i<n; ++i){
            if(arr[i] > curr)
                maxx = max(maxx, arr[i]-curr);
            else{
                curr = arr[i];
            }
        }
        return maxx;
    }
};