class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n,0);
        left[0] = 0;
        right[n-1] = 0;
        for(int i = 1; i<n; i++){
            left[i] = max(left[i-1], arr[i-1]);
        }
        for(int i = n-2; i>=0; i--){
            right[i] = max(right[i+1], arr[i+1]);
        }
        int sum = 0;
        for(int i = 1; i<n-1; i++){
            int x = min(left[i], right[i]);
            if(x > arr[i]){
                sum+= x-arr[i];
            }
        }
        return sum;
        
    }
};