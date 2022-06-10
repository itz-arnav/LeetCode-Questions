// { Driver Code Starts



#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends


class Solution{
public:
    vector<int> gcd(int a, int b){
        // code here
        vector<int> ans;
        if(b == 0){
            ans.push_back(a);
            ans.push_back(1);
            ans.push_back(0);
            return ans;
        }
        
        auto temp = gcd(b, a%b);
        ans.push_back(temp[0]);
        ans.push_back(temp[2]);
        ans.push_back(temp[1] - temp[2]*(a/b));
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        vector<int> v = ob.gcd(a,b);
        if(v.size()!=3)
            return 0;
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
    }
    return 0; 
}  // } Driver Code Ends