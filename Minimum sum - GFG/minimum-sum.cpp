//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr, arr+n);
        int i = n-1, j = n-2;
        string ans = "";
        int carry = 0;
        while(i >= 0 or j >= 0 or carry == 1){
            int temp = carry; 
            if(i >= 0){
                temp += arr[i];
                i-=2;
            }
            if(j >= 0){
                temp += arr[j];
                j-=2;
            }
            if(temp == 0)
            break;
            int current = temp%10;
            carry = temp/10;
            ans.push_back('0'+current);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends