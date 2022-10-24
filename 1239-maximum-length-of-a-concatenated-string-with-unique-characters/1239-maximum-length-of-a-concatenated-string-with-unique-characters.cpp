class Solution {
public:
    bool check(string s,unordered_map<char,int> &map){
        unordered_set<char> mp;
        for(auto it:s){
            if(mp.find(it)!=mp.end())return false;//found duplicate in the same string
                mp.insert(it);
            if(map[it]>0)return false;//found duplicate in the map and current string
        }
        return true;
    }
    int solve(int i,vector<string> &arr,unordered_map<char,int> &map){
        if(i>=arr.size())return 0;
        int x=0;
        x=solve(i+1,arr,map);//not pick
        if(check(arr[i],map)){ //checking that it is possible to pick or not
            for(auto it:arr[i])map[it]++; //putting in our map
            x=max(x,(int)(solve(i+1,arr,map)+arr[i].size()));
            for(auto it:arr[i]){//backtracking
                map[it]--;
            }
        }
        return x;
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> map;
        return solve(0,arr,map);
    }
};