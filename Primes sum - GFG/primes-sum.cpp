//{ Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    bool isPrime(int n){
      if(n <= 1)
      return false;
      for(int i = 2; i*i <= n; ++i){
          if(n%i ==0)
          return false;
      }
      return true;
  }
    string isSumOfTwo(int N){
        if(N < 4)
        return "No";
        if(isPrime(N-2) or N%2 == 0)
        return "Yes";

        return "No";
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends