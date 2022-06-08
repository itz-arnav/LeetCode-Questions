// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
   vector <int> nearlySorted(int nums[], int n, int k){
        vector<int> ans(n);
        set<int> st;

        for(int j=0;j<k;j++)    st.insert(nums[j]);


        for(int i=0;i<n;i++)
        {
            if(i+k<n) st.insert(nums[i+k]);
            ans[i] = *st.begin();
            st.erase(*st.begin());
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends