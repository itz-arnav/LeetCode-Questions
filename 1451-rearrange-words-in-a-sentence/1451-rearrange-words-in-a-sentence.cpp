class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<int, string>> beSorted;
        map<int, string> sizeStrMap;
        string res = "";
        for (int i = 0; i < text.size(); i++) {
            string word = "";
            while (isalpha(text[i])) {
                word += tolower(text[i]);
                i++;
            }
            sizeStrMap[word.size()] += word + " ";
        }
        
        for (auto pair : sizeStrMap) {
            res += pair.second;
        }
        
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};