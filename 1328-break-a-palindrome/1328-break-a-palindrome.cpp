class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        if(n == 1)
            return "";
        
        while(i < j){
            if(s[i] >= 'b'){
                s[i] = 'a';
                return s;
            }
            i++,j--;
        }
        j = n-1;
        while(j >= 0){
            if(s[j] == 'a'){
                s[j] = 'b';
                break;
            }
        }
        return s;
    }
};