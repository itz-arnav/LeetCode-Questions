class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        map<int,int> mp;
        for(int i = 0; i<arr.size(); ++i){
            if(arr[i] == 5){
                mp[5]++;
            }
            else if(arr[i] == 10){
                if(mp[5] == 0){
                    return false;
                }
                mp[5]--;
                mp[10]++;
            }
            else{
                if(mp[10] == 0 and mp[5] < 3){
                    return false;
                }
                else if(mp[10] > 0 and mp[5] > 0){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5] >= 3){
                    mp[5]-=3;
                }
                else if(mp[5] < 3){
                    return false;
                }
            }
        }
        return true;
    }
};