class Solution {
public:
   string bestoddpal(string s){
    string ans="";
    int n=s.size();
    for(int mid=0;mid<n;mid++){
        string temp="";
        temp+=(s[mid]);
        if(temp.size()>ans.size()){
            ans=temp; 
        }
        for(int i=1;mid-i>=0 && mid+i<n;i++){
            if(s[mid-i]!=s[mid+i]){
                break;
            }
            else{
                temp.insert(temp.begin(), s[mid-i]);
                temp.push_back(s[mid+i]);
            }
            if(temp.size()>ans.size()){
                    ans=temp; 
            }
        }
    }
    return ans;
}

string bestevenpal(string s){
	string ans="";
    
    int n=s.size();
    for(int mid=0;mid<n;mid++){
        string temp="";
        for(int i=1;mid-i+1>=0&&mid+i<n;i++){
            if(s[mid-i+1]!=s[mid+i]){ 
                break;
            }
            else{ 
                temp.insert(temp.begin(), s[mid-i+1]);
                temp.push_back(s[mid+i]);
            }
            if(temp.size()>ans.size()){
                ans=temp;     
            }
        }
    }
    return ans;

}
    
    string longestPalindrome(string s) {
        

        string t1=bestoddpal(s);
        string t2=bestevenpal(s);
        
        if(t1.size()>t2.size()){
            return t1;
        }
        return t2;
    }
};