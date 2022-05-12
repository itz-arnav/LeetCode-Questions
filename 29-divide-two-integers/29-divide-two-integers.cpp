class Solution {
public:
    int divide(int c, int d) {
        if (c == INT_MIN && d == -1) return INT_MAX;
        long a = abs(c), b = abs(d), res = 0;
        for(int i = 0; i<32 and (a-b)>=0; i++){
            for(int j = 31; j>=0; j--){
                if(a - b*(1LL<<j) >= 0){
                    res += 1LL<<j;
                    a -= b*(1LL<<j);
                }
            }
        }
        return (c > 0) == (d > 0) ? res : -res;
    }
};