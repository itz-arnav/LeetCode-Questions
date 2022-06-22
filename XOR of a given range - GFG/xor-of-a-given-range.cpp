// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
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
    
    
    int getXor(vector<int>&arr, int x, int y){
        // Code here
        int n = arr.size();
        
        vector<int> tree(4*n + 5, 0);
        buildTree(arr,0, n-1, tree, 1);
        
        return query(0, n-1, x, y, tree, 1);
        
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        if(a > b)swap(a, b);
        Solution obj;
        int ans = obj.getXor(nums, a, b);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends