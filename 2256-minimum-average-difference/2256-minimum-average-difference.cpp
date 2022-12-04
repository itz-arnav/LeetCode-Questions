class Solution {
public:
    #define ll long long
    int minimumAverageDifference(vector<int>& arr) {
        int n = arr.size();
        vector<ll> left(n, 0);
        vector<ll> right(n, 0);
        left[0] = arr[0];
        for(int i = 1; i<n; i++){
            left[i] += left[i-1] + arr[i];
        }
        right[n-1] = 0;
        for(int i = n-2; i>=0; i--){
            right[i]+= right[i+1] + arr[i+1];
        }
        
        int idx = 0, minn = INT_MAX;
        for(int i = 0; i<n-1; i++){
            int l = left[i]/(i+1);
            int r = right[i]/(n-i-1);
            int m = abs(l-r);
            if(m < minn)
            {
                minn = m;
                idx = i;
            }
        }
        if(left[n-1]/n < minn){
            idx = n-1;
        }
        return idx;
    }
};