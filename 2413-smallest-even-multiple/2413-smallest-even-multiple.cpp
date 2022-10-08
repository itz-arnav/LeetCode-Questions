class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(__gcd(2,n) == 1)
            return 2*n;
        return n;
    }
};