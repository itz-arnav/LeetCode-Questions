class Solution {
public:
    int helper(int n,int k){
        if(n==1)
            return 0;
        return (helper(n-1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for converting 0-based indexing to 1-based indexing
    }
};