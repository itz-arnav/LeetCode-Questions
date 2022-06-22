// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void buildTree(vector<int> &arr, int s, int e, vector<int> &tree, int index){
	if(s == e){
		tree[index] = arr[s];
		return;
	}
	int mid = s + (e-s)/2;
	buildTree(arr, s, mid, tree, 2*index);
	buildTree(arr, mid+1, e, tree, 2*index + 1);
	tree[index] = (tree[2*index] ^ tree[2*index + 1]);
}

int query(int ss, int ee, int qs, int qe, vector<int>&tree, int index){
	if(ss > qe or qs > ee){
		return 0;
	}
	else if(qs <= ss and qe >= ee){
		return tree[index];
	}
	else{
		int mid = ss + (ee - ss)/2;
		int left = query(ss, mid, qs, qe, tree, 2*index);
		int right = query(mid+1, ee, qs, qe, tree, 2*index + 1);
		return (left ^ right);
	}
}


    vector<int> specialXor(int N, int Q, int a[], vector<int> qr[])
    {
        // code here
        vector<int> ans, arr(N+3);
        
        int x = 0;
        for(int i = 0; i<N; ++i){
            x^=a[i];
            arr[i+1]= a[i];
        }
        vector<int> tree(4*N+5, 0);
        buildTree(arr, 1, N, tree, 1);
        
        for(int i = 0; i<Q; ++i){
            ans.push_back(x ^ query(1, N, qr[i][0], qr[i][1], tree, 1));
        }
        
        return ans;
    }
}; 

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}  // } Driver Code Ends