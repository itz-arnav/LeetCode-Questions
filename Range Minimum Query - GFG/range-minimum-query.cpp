// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The functions which 
builds the segment tree */


int *tree;
void buildTree(int *arr, int s, int e, int *tree, int index){
	if(s == e){
		tree[index] = arr[s];
		return;
	}
	int mid = s + (e-s)/2;
	buildTree(arr, s, mid, tree, 2*index);
	buildTree(arr, mid+1, e, tree, 2*index + 1);
	tree[index] = min(tree[2*index], tree[2*index + 1]);
}

int query(int ss, int ee, int qs, int qe, int *tree, int index){
	if(ss > qe or qs > ee){
		return INT_MAX;
	}
	else if(qs <= ss and qe >= ee){
		return tree[index];
	}
	else{
		int mid = ss + (ee - ss)/2;
		int left = query(ss, mid, qs, qe, tree, 2*index);
		int right = query(mid+1, ee, qs, qe, tree, 2*index + 1);
		return min(left, right);
	}
}

int *constructST(int arr[],int n)
{
  //Your code here
  
  tree = new int[4*n + 1];
  buildTree(arr, 0 , n-1, tree, 1);
  return tree;
  
}


/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    return query(0, n-1, a, b, st, 1);

}