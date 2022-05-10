// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        int lmin[n], rmax[n];
        lmin[0] = arr[0];
        for (int i=1; i<n; i++){
            lmin[i] = min(arr[i], lmin[i-1]);
        }
        
        rmax[n-1] = arr[n-1];
        for (int i=n-2; i>=0; i--){
            rmax[i] = max(arr[i], rmax[i+1]);
        }
        
        int i=0, j=0;
        int res = -1;
        while(i<n and j<n){
            if (lmin[i] <= rmax[j]){
                res = max(res, j-i);
                j++;
            }else{
                i++;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends