class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mors{
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
            "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_map<string, int> mp;
        for(auto w: words){
            string t = "";
            for(auto c: w) t += mors[c-'a'];
            mp[t]++;
        }
        return mp.size();
    }
};