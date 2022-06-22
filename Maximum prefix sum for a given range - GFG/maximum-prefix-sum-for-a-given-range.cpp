// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
  public:
    vector<int> maxPrefixes(int a[], int L[], int R[], int N, int Q) {
       int i=0;
       vector<int>ans;
       while(i<Q){
           int maxval=INT_MIN;
           int pre=0;
           for(int j=L[i];j<=R[i];j++){
               pre+=a[j];
               maxval=max(maxval,pre);
           }
           ans.push_back(maxval);
           i++;
       }
       return ans; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n], L[q], R[q];
        
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < q; i++) cin >> L[i] >> R[i];
        Solution obj;
        vector<int> ans = obj.maxPrefixes(a, L, R, n, q);
        for (auto it : ans) 
            cout << it << " ";
        cout << endl;
    }
}
  // } Driver Code Ends