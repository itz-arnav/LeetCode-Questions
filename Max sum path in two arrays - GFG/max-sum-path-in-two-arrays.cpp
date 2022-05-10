// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
    
        int i=0,j=0,path1=0,path2=0;
        while(i<l1 && j<l2){
            if(A[i]<B[j]){
                path1+=A[i++];
            }else if(A[i]>B[j]){
                path2+=B[j++];
            }else{
                path1+=A[i++];
                path2+=B[j++];
                path1=max(path1,path2);
                path2=max(path1,path2);
            }
        }
        while(i<l1){
            path1+=A[i++];
        }
        while(j<l2){
            path2+=B[j++];
        }
        return max(path1,path2);
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends