class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.size() ;
        //edge case 
        if(n ==0 ) return 0 ; 
        
        int i=0 , j=0 ; 
        set <char> st ; 
        
        int ans = INT_MIN ; 
        while(j < s.size()){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]) ; 
                j++ ;
                int m = st.size() ; 
                ans = max(ans , m) ; 
            }else{
                st.erase(s[i]) ; 
                i++ ; 
            }
        }
        return ans ; 
    }
};