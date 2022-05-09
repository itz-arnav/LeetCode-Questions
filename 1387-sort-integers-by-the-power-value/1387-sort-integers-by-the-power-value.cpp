class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;i++){
            v.push_back({power(i),i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
    int power(int num){
        int cnt=0;
        while(num!=1){
            if(num%2==0){
                num=num/2;
            }
            else{
                num=3*num+1;
            }
            cnt++;
        }
        return cnt;
    }
};