// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    // function to find totient of n
    long long ETF(long long N){
        // code here
        long long x = N;
        long long i = 2;
        long long ans = N;
        while(i*i <= N){
            if(x%i==0){
                while(x%i == 0){
                    x/=i;
                }
                ans = ans*(i-1)/i;
            }
            i++;
        }
        if(x > 1){
            ans = ans*(x-1)/x;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout << ob.ETF(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends