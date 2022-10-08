class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int best = 1e8;
        for(int i = 0; i<n; ++i){
            int j = i+1, k = n-1;
            while(j < k){
                int val = arr[i] + arr[j] + arr[k];
                if(abs(target - val) < abs(target - best)){
                    best = val;
                }
                if(arr[i] + arr[j] + arr[k] < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return best;
    }
};