class Solution {
public:
    int wateringPlants(vector<int>& arr, int c) {
        int x = c;
        int ans = 0;
        for(int i = 0; i<arr.size(); ++i){
            if(arr[i] > x){
                ans += i + (i+1);
                x = c - arr[i];
            }
            else{
                x -= arr[i];
                ans++;
            }
        }
        return  ans;
    }
};