class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        int first = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'u' or s[i] == 'o'){
                if(i < s.length()/2){
                    first++;
                }
                count++;
            }
            else if(s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'U' or s[i] == 'O'){
                if(i < s.length()/2){
                    first++;
                }
                count++;
            }
        }
        return (2*first == count);
    }
};