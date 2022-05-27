


public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        if(n >= 0){
        
        while(n > 0){
            count += n & 1 ; 
            n = n>>1;
            
        }
        }
        else{
            n = ~n;
            while(n > 0){
            count += n & 1 ; 
            n = n>>1; 
            } 
            count = 32 - count;
        }
        return count;
        
    }
}

/// doubt understood this question in cpp but not in java
