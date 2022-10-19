class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> mp;
        char curr = 'a';
        for(auto &x : key){
            if(x == ' ')
                continue;
            if(mp.find(x) == mp.end()){
                mp[x] = curr;
                curr++;
            }
        }
        for(int i = 0; i<message.size(); ++i){
            if(message[i] != ' ')
            message[i] = (char)mp[message[i]];
        }
        return message;
    }
};