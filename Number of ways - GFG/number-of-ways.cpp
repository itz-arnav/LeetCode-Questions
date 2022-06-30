// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long int>dp;
public:
    long long int arrangeTiles(int N){
       dp.resize(N+1,-1);
       return solve(N);
     }
    long long int solve(int N)
    {
       //valid construction if N==0;
       if (N==0) return 1;
       //inValid construction if N<0;
       if (N<0)  return 0;
       if(dp[N]!=-1)
        return dp[N];
       //lengthwise adjustment+breadthwise adjustment(l==1 && b==4)
       return dp[N]=solve(N-1)+solve(N-4);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends