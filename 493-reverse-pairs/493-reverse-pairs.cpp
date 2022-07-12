class Solution {
public:
    
    int ans = 0;
    void mergeSort(vector<int>& arr, vector<int>& temp, int start, int mid, int end){
        int i = start, j = mid+1;
        while(i <= mid and j<=end){
            if(1LL*arr[i] > 2LL*arr[j]){
                //cout<<"start : "<<start<<" and end : "<<end<<endl;
                ans += mid - i + 1;
                j++;
            }
            else{
                i++;
            }
        }

        int k = start;
        i = start, j = mid+1;
        while(i <= mid and j <= end){
            temp[k++] = ((arr[i] <= arr[j])? arr[i++] : arr[j++]);
        }
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j <= end)
        {
            temp[k++] = arr[j++];
        }
        k = start;
        while(k <= end){
            arr[k] = temp[k];
            k++;
        }
    }
    
    void solve(vector<int>& nums, vector<int>& temp, int start, int end){
        if(start >= end)
            return;
        int mid = start + (end-start)/2;
        solve(nums, temp, start, mid);
        solve(nums,temp,  mid+1, end);
        mergeSort(nums, temp, start, mid, end);
    }
    int reversePairs(vector<int>& nums) {
vector<int> temp = nums;
        solve(nums, temp, 0, nums.size()-1);
        // for(auto &x : nums)
        //     cout<<x<<" ";
        return ans;
    }
};