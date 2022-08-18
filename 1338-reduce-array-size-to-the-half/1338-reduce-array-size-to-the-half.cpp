class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
    
        vector<int> v;
        int count = 1;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i] == arr[i-1])
                count++;
            else{
                v.push_back(count);
                count=1;
            }
        }
        v.push_back(count);
        
        sort(v.begin(), v.end());
        
        int n = arr.size()/2, ans = 0;
        for(int i = v.size()-1; n>0 && i>=0; i--){
            ans++;
            n-=v[i];
        }
        return ans;
    }
};