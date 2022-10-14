//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int findIndex(int arr[], int X, int Y, int n);


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,y;
		cin>>n>>x>>y;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		cout<<findIndex(a,x,y,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends



int findIndex(int arr[], int X, int Y, int N)
{
    int ans = -1;
    int x = 0, y = 0;
    for(int i = 0; i<N; ++i){
        if(arr[i] == X)
        x++;
        else if(arr[i] == Y)
        y++;
        if(x == y and x >= 1)
        ans = i;
    }
    return ans;
}