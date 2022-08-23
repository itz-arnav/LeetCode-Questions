class Solution {
public:
    bool isPowerOfFour(int num) {
        bool ans=true;
        if(num <= 0)
            return false;
        long n=(num);
        while(n){
            if(n>1 && n%4) {
                ans=false; break;
            }
            n/=4;
        }
        return ans;
    }
};