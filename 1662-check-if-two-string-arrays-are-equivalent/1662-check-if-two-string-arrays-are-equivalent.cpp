class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";
        for(auto &x : word1)
            a.append(x);
        for(auto &x : word2)
            b.append(x);
        
        return a==b;
    }
};