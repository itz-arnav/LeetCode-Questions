class Solution {
public:
    int minOperations(int n) {
        int low = 1, high = 2*n -1;
        int ct = 0;
        while(low < high){
            ct += (high - low)/2;
            low+=2;
            high-=2;
        }
        return ct;
    }
};