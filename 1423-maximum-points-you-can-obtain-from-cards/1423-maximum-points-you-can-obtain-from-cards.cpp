class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int maxsum = 0;
        int curr = 0;
        int n = arr.size();
        int left = 0;
        int right = n-1;
        for(int i = 0; i<k; i++){
            curr+=arr[i];
        }
        maxsum = curr;
        for(int i = k-1; i>=0; i--){
            curr -= arr[i];
            curr += arr[right];
            right--;
            maxsum = max(maxsum, curr);
        }
        return maxsum;
    }
};