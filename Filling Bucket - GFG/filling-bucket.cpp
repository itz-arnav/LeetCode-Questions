//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e8;
    int dp[100005];
    long long solve(int n){
        if(n <= 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        if(dp[n] != -1)
        return dp[n];
        return dp[n] = (solve(n-1) + solve(n-2))%mod;
    }
    int fillingBucket(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends