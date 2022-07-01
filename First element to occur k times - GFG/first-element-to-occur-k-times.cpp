// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        map<int, int> mp, mp2;
        for(int i = 0; i<n; ++i){
            if(mp.find(a[i]) == mp.end())
            mp[a[i]] = 0;
            
            mp[a[i]]++;
            if(mp[a[i]] == k)
            return a[i];
        }
        
        return -1;
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}  // } Driver Code Ends