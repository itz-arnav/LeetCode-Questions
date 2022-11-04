class Solution {
public:
    bool isvw(char c){
        if(c < 'a')
            c+=32;
         return (c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u');
            
    }
    string reverseVowels(string s) {
        vector<char> vw;
        for(auto c: s){
            if(isvw(c))
                vw.push_back(c);
        }
        int j = vw.size()-1;
        for(int i = 0; i<s.size(); i++){
            if(isvw(s[i])){
                s[i] = vw[j];
                j--;
            }
        }
        return s;
    }
};