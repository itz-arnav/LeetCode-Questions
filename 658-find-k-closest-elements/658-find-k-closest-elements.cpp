class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int n = arr.size();
        if(idx == n){
            idx--;
        }
        if(arr[idx] != x){
            if(idx > 0){
                if(abs(arr[idx - 1] - x) <= abs(arr[idx] - x)){
                    idx--;
                }
            }
        }
        int count = 1;
        int si = idx - 1;
        int ei = idx + 1;
        vector<int> ans;
        ans.push_back(arr[idx]);
        while(count < k){
            if(si >= 0 and ei < n){
                if(abs(arr[si] - x) <= abs(arr[ei] - x)){
                    ans.push_back(arr[si]);
                    si--;
                }
                else{
                    ans.push_back(arr[ei]);
                    ei++;
                }
            }
            else if(si >= 0){
                ans.push_back(arr[si]);
                    si--;
            }
            else{
                ans.push_back(arr[ei]);
                    ei++;
            }
            count++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};