class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        if(bound < 2)
            return ans;
        if(x == 1 and y == 1)
        {
            if(bound < 2)
                return ans;
            else
                return {2};
        }
        if(y==1){
            int z = log(bound)/log(x);
            for(int i = 0; i<=z; i++){
                if(1 + pow(x,i) <= bound)
                ans.push_back(1 + pow(x,i));
            }
            return ans;
        }
        if(x == 1){
            int z = log(bound)/log(y);
            for(int i = 0; i<=z; i++){
                if(1 + pow(y,i) <= bound)
                ans.push_back(1 + pow(y,i));
            }
            return ans;
        }
        
        unordered_set<int> st;
        int lowi = log(bound)/log(x);
        int highi = log(bound)/log(y);
        for(int i = 0; i<=lowi; i++){
            for(int j= 0; j<=highi; j++){
                int t = pow(x,i) + pow(y,j);
                if(t <= bound)
                st.insert(t);
            }
        }
        for(auto &x: st){
            ans.push_back(x);
        }
        return ans;
    }
};