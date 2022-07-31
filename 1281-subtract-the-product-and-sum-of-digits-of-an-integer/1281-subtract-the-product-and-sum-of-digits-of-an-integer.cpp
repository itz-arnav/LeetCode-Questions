class Solution {
public:
    int subtractProductAndSum(int n) {
        int ans = 1;
        int sum = 0;
        while(n){
            int d = n%10;
            sum+=d;
            ans*=d;
            n/=10;
        }
        return ans - sum;
    }
};