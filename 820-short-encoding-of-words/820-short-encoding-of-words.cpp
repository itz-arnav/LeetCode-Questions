class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0,n=words.size();
        unordered_map<string, bool>mp;
        for(int i=0;i<n;i++){
            bool f=false;
            bool twice = false;
            int s1=words[i].size();
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                int s2=words[j].size();
                int a=s1-1,b=s2-1;
             //   int m=max(s1,s2);
                
                while(a>=0 && b>=0){
                    if(words[i][a]!=words[j][b]) break;
                    a--; b--;
                }
                if(a == -1 and b == -1){
                    twice = true;
                    
                }
                if(a<0) f=true;
            }
            if(!f) ans+=s1+1;
            else if(twice and mp[words[i]]==false){
                ans += s1+1;
                mp[words[i]] = true;
            }
        }
        //if(!ans) ans+=words[0].size()+1;
        return ans;
    }
};