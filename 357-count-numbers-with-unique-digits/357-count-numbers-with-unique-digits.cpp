class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n == 0){
            return 1;
        }
        int ans = 10;
        int dig = 2;
        while(dig <= n){
            int start = 9;
            int curr = 9;
            int x = 1;
            while(x < dig){
                curr*=start;
                x++;
                start--;
            }
            dig++;
            ans += curr;
        }
        return ans;
    }
};