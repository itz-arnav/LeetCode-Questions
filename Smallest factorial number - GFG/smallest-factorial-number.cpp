// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int  findNum(int n)
   {
       
       
       int low = 0;
       int high = 5*n;
       int ans = low;
       while(low <= high){
           int mid = (low + high)/2;
           int zeros = findzeros(mid);
           if(zeros >= n)
           {
               ans = mid;
               high = mid - 1;
           }
           else  low = mid + 1;
       }
       return ans;
       
   }
   int findzeros(int x){
       int demo = 5;
       int zeros = 0;
       while(x >= demo)
       {
           zeros+=(x/demo);
           demo*= 5;
       }
       return zeros;
       
   }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends