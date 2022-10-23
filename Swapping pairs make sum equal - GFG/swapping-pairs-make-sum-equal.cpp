//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        sort(A,A+n);
        sort(B,B+m);
        int a = 0, b = 0;
        for(int i =0; i<n; ++i){
            a += A[i];
        }
        for(int i = 0; i<m; ++i){
            b += B[i];
        }
        int i = 0, j = 0;
        while(i < n and j < m){
            if(a - A[i] + B[j] == b - B[j] + A[i]){
                return true;
            }
            else if(a - A[i] + B[j] < b - B[j] + A[i]){
                j++;
            }
            else{
                i++;
            }
        }
        return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends