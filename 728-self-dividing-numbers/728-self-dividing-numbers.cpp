class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
     vector<int> ans;
        for(int i = left; i<=right; i++){
            int r = i;
            bool flag = true;
            while(r > 0){
                int d = r%10;
                if(d == 0){
                    flag = false;
                    break;
                }
                if(i%d != 0)
                {
                    flag = false;
                    break;
                }
                r/=10;
            }
            if(flag)
                ans.push_back(i);
        }
        return ans;
    }
};