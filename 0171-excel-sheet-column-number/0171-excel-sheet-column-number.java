class Solution {
    public int titleToNumber(String columnTitle) {
        int multiplyFactor = 1;
        int n = columnTitle.length();
        int ans = 0;
        for(int i = n-1; i>=0; --i){
            int current_Value = columnTitle.charAt(i) - 'A' + 1;
            ans = ans + multiplyFactor*current_Value;
            multiplyFactor *= 26;
        }
        return (int)ans;
    }
}