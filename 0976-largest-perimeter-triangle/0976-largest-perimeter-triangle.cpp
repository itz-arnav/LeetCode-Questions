class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int a = n-1, b=  n-2, c = n-3;
        while(c >= 0){
            int x = arr[a], y = arr[b], z = arr[c];
            if(x + y > z and x + z > y and y + z > x){
                return x + y + z;
            }
            else{
                a--,b--,c--;
            }
        }
        return 0;
    }
};