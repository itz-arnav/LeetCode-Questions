class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int ans = INT_MAX;
        int val = INT_MAX;
        for(int i = 0; i<n; i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                
                if(abs(target - arr[i] - arr[j] - arr[k]) < ans){
                    ans = abs(target - arr[i] - arr[j] - arr[k]);
                    val = arr[i] + arr[j] + arr[k];
                }
                if(arr[i] + arr[j] + arr[k] > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return val;
    }
};