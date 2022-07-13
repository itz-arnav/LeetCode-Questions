class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         map<int,int> m;
        set<vector<int>> st;
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) m[nums[i]]=i;
        for(int i=0;i<n;i++){
            vector<int> temp(3);
            for(int j=i+1;j<n;j++){
                int s=0;
                bool f=false;
                if(j!=i){
                    s=nums[i]+nums[j];
                    f=true;
                }
                int d=0-s;
                if(f && m.find(d)!=m.end() && m[d]!=i && m[d]!=j)
                {
                    temp[0]=nums[i]; temp[1]=nums[j];
                    temp[2]=d;
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
        for(auto it:st) ans.push_back(it);
        return ans;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);