class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool f1=true,f2=true;
        int n=s1.length();
        for(int i=0;i<n;i++)
        {
            if(s1[i]<s2[i])f1=false;
            if(s2[i]<s1[i])f2=false;
        }
        if(f1 or f2)return true;
        return false;
    }
};