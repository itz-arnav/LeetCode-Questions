class Solution {
public:
    int minCost(string c, vector<int>& arr) {
        int ans = 0;
        int prev = 0;
        int n = c.size();
        for(int i = 1; i<n; ++i){
            if(c[i] == c[prev]){
                ans+= min(arr[i], arr[prev]);
                if(arr[i] > arr[prev]){
                    prev = i;
                }
            }
            else{
                cout<<i<<endl;
                prev = i;
            }
        }
        return ans;
    }
};