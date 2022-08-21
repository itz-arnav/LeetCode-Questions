class Solution {
public:
    bool canReplace(string &target, int pos, string &stamp){
        for(int i = 0; i< stamp.length(); i++){
            if(target[pos+i] != '?' && target[pos+i] != stamp[i]){
                return false;
            }
        }
        return true;
    }
    
    void replace(string &target, int pos, int &len, int &count){
        for(int i = 0; i<len; i++){
            if(target[pos+i] != '?'){
                target[pos+i] = '?';
                count++;
            }
        }
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int tlen = target.length(), slen = stamp.length();
        int count = 0;
        vector<bool> vis(tlen, false);
        vector<int> res;
        
        while(count != tlen){
            bool flag = false;  //to check weather we can replace or not
            for(int i = 0; i<=tlen-slen; i++){
                if(!vis[i] && canReplace(target, i, stamp)){
                    replace(target, i, slen, count);
                    vis[i] = true;
                    flag = true;
                    res.push_back(i);
                    
                    if(count == tlen){
                        break;
                    }
                }
            }
            
            if(!flag){
                vector<int> temp;
                return temp;
            }
        }
        
        //reverse the result since we have used reverse approach answer is stored in res array in reverse order
        reverse(res.begin(), res.end());
        return res;
    }
};