// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_map<int,int> mp;
      for(int i = 0; i<n; ++i){
          mp[arr[i]]++;
      }
      
      int best = 0;
      for(auto &x : mp){
          int p = x.first;
          if(mp.find(p-1) != mp.end())
          continue;
          
          int t = 0;
          for(t = 1; t<=n; t++){
              if(mp.find(t+p) == mp.end())
              break;
          }
          best = max(best, t);
      }
      return best;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends