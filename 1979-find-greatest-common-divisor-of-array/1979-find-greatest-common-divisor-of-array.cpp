class Solution {
public:
    int findGCD(vector<int>& arr) {
        int n = arr.size();
        int smallest = 1e7, largest = 0;
        for(int i = 0; i<n; ++i){
            smallest = min(smallest, arr[i]);
            largest = max(largest, arr[i]);
        }
        return __gcd(smallest, largest);
    }
};