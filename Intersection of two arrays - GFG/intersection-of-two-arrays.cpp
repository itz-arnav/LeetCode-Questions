//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_map<int,int> mp, mp2;
        for(int i = 0; i<n; ++i){
            mp[a[i]]++;
        }
        for(int j = 0; j<m; ++j){
            mp2[b[j]]++;
        }
        int ans = 0;
        for(int i = 0; i<n; ++i){
            if(mp[a[i]] > 0 and mp2[a[i]] > 0){
                ans++;
                mp[a[i]] = 0;
                mp2[a[i]] = 0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends