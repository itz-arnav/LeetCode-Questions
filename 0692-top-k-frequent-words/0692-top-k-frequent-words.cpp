class Solution {
public:
    #define dt pair<int,string>
    class cmp {
  public:
    bool operator() (const dt &p1, const dt &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it:words) mp[it]++;
        priority_queue<dt,vector<dt>,cmp> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans;
        while(pq.size()){
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            ans.push_back(pq.top().second);
            pq.pop();
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};