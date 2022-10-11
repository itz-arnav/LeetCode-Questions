class Solution {
public:
    int minTimeToType(string word) {
        char prev = 'a';
        int ans = 0;
        for(char c : word){
            int ans1 = 50, ans2 = 50;
            //right
            if(c < prev)
                ans1 = 'z' - prev +1 + c - 'a';
            else
                ans1 = c - prev;
            //left
            if(c > prev)
                ans2 = prev - 'a' + 1 + 'z' - c;
            else
                ans2 = prev - c;
            
            ans += 1 + min(ans1, ans2);
            prev = c;
        }
        return ans;
    }
};