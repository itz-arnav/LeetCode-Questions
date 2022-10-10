class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(auto x : arr){
            sum+=x;
        }
        
        if(sum%3)
            return false;
        
        sum /= 3;
        
        vector<int> prefix(n, 0), suffix(n, 0), pos(n, 0);
        
        for(int i = 0; i<n; ++i){
            prefix[i] = arr[i];
            if(i > 0)
                prefix[i]+=prefix[i-1];
        }
        for(int i = n-1; i>=0; i--){
            suffix[i] = arr[i];
            if(i < n-1){
                suffix[i] += suffix[i+1];
            }
            if(suffix[i] == sum){
                pos[i] = true;
            }
            if(i < n-1)
                pos[i] |= pos[i+1];
        }
        
        for(int i = 0; i<n-2; ++i){
            if(prefix[i] == sum and pos[i+2])
                return true;
        }
        return false;
    }
};