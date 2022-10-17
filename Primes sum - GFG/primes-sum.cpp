//{ Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int prime[10004];
    void sieve(){
        fill(prime, prime+10004, 1);
        prime[0] = prime[1] = 0;
        for(int i = 2; i<10004; i++){
            if(prime[i]){
                for(int j = i*i; j<10004; j+=i){
                    prime[j] = 0;
                }
            }
        }
    }
    string isSumOfTwo(int N){
        sieve();
        if(N < 4)
        return "No";
        if(prime[N-2])
        return "Yes";

        for(int i = 3; 2*i <= N; i+=2){
            if(prime[i] and prime[N-i]){
                return "Yes";
            }
        }
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