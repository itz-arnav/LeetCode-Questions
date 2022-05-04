class Solution {
public:
    int maxVowels(string s, int k) {
       int maxi=0,start=0,end=0,curr=0;
      unordered_set<char>st={'a','e','i','o','u'};
            while(end<s.size())
            {
               if(end-start+1==k+1)
               {
               if(st.find(s[end])!=st.end()){
                   curr++;
               } 
                if(st.find(s[start])!=st.end()){
                   curr--;
               } 
                   end++;
                   start++;
                   maxi = max(maxi, curr);
               }
               else if(end-start+1<=k)
               
               {
                 if(st.find(s[end])!=st.end())
                 {
                    curr++;
                    maxi = max(maxi, curr);   
                 }
                   end++;
                }
            }
        return maxi;
    }
};