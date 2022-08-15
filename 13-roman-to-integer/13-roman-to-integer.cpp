class Solution {
public:
    int priority(char ch){
        if(ch=='I'){
            return 1;
        }
        else if(ch=='V'){
            return 2;
        }
        else if(ch=='X'){
            return 3;
        }
        else if(ch=='L'){
            return 4;
        }
        else if(ch=='C'){
            return 5;
        }
        else if(ch=='D'){
            return 6;
        }
        else if(ch=='M'){
            return 7;
      }
        return 0;
    }
    int findchar(char ch){
        if(ch=='I'){
            return 1;
        }
        else if(ch=='V'){
            return 5;
        }
        else if(ch=='X'){
            return 10;
        }
        else if(ch=='L'){
            return 50;
        }
        else if(ch=='C'){
            return 100;
        }
        else if(ch=='D'){
            return 500;
        }
           return 1000;
}
    int romanToInt(string s) {
        int n=s.length();
        int num=0;
        for(int i=0;i<n;i++){
            if(i==n-1){
                num+=findchar(s[i]);
                continue;
                
            }
            else if(priority(s[i]) >= priority(s[i+1])){
                num+= findchar(s[i]);
                
            }
            else if(priority(s[i]) < priority(s[i+1])){
                num-= findchar(s[i]);
            } 
        }
        return num;
    }
};