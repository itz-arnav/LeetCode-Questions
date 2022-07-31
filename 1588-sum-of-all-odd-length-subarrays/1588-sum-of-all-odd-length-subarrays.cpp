class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i<n; ++i){
            ans += (1 + (i+1)*(n-i))/2  * arr[i];
        }
        return ans;
    }
};