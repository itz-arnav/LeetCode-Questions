class Solution {
public:
    #define ll long long
    long long minimumMoney(vector<vector<int>>& arr) {
        int n=arr.size();
sort(arr.begin(),arr.end(),[&](const vector<int> &a, const vector<int> &b){
ll x=min(-a[0],-a[0]+a[1]-b[0]);
ll y=min(-b[0],-b[0]+b[1]-a[0]);
if(x==y){
if(a[1]==b[1]) return a[0]>b[0];
return a[1]<b[1];
}
return x<y;
});
ll ans=1e16,curr=0;
for(vector<int> x: arr){
curr-=x[0];
ans=min(ans,curr);
curr+=x[1];
}
return abs(min(0LL,ans));
    }
};