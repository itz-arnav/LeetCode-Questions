// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int ac = __builtin_popcount(a);
        int bc = __builtin_popcount(b);
        
        if(ac <= bc){
            int x = a;
            bc -= ac;
            for(int i = 0; i<32; ++i){
                if(bc == 0)
                break;
                if(a & (1<<i))
                continue;
                x |= (1<<i);
                bc--;
                
            }
            return x;
        }
        else{
           // cout<<ac<<" "<<bc<<endl;
            int x = 0;
            for(int i = 31; i>=0; i--){
                if(bc == 0)
                    break;
                if(a & (1<<i)){
                    x |= (1<<i);
                    bc--;
                }
            }
            return x;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends