class Solution {
public:
     int mod=1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,vector<pair<int,int>>> mp;
        map<int,long> dp;
        sort(arr.begin(),arr.end());
        for(int i = 0; i<arr.size(); ++i){
            for(int j = 0; j<arr.size(); j++){
                int other = arr[i]/arr[j];
                if(arr[i]%arr[j] == 0){
                    if(binary_search(arr.begin(),arr.end(),other))
                    {
                       mp[arr[i]].push_back({arr[j],other});
                    }
                }
            }
        }
        long long ans=0;
        for(int i = 0; i<arr.size(); ++i){
        long s = 1;
        for(auto x : mp[arr[i]]){
                s= (s + 1LL*dp[x.first]*dp[x.second])%mod;
            
        }
        dp[arr[i]]=s;
        ans=(ans+dp[arr[i]])%mod;
        }
        // long res = 0;
        // sort(arr.begin(), arr.end());
        // for (int i = 0; i < arr.size(); ++i) {
        //     dp[arr[i]] = 1;
        //     for (int j = 0; j < i; ++j)
        //         if (arr[i] % arr[j] == 0)
        //             dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
        //     res = (res + dp[arr[i]]) % mod;
        // }
        for(int i = 0; i<arr.size(); ++i){
            cout<<arr[i]<<" : "<<dp[arr[i]]<<endl;
        }
        cout<<endl;
        return ans;
    }
};