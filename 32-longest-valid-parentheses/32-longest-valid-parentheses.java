class Solution {
    public int longestValidParentheses(String s) {
        int open = 0 , close = 0;
        int max = 0;
        
        // 0 -- n
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(c == '('){
                open++;
            }
            else{
                close++;
            }
            
            if(open == close){
                int len = open + close;
                max = Math.max(max,len);
            }
            else if(close > open ){
                open = close = 0;
            }
        }
        
        open = close = 0;
        // n -- 0
        for(int i= s.length()-1; i>=0 ;i--){
            char c = s.charAt(i);
            if(c == '('){
                open++;
            }
            else{
                close++;
            }
            
            if(open == close){
                int len = open + close;
                max = Math.max(max,len);
            }
            else if(open > close ){
                open = close = 0;
            }
        }
        
        return max;
    }
}