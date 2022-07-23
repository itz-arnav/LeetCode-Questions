class Solution {
public:
    void merge(vector<pair<int,int>> &arr, vector<int> &ans, int start, int mid, int end)
    {
         vector<pair<int,int>>temp(end - start + 1); 
         int left=start, right = mid+1; 
         int ct=0; 
         int k = 0;
         while(left<=mid and right<=end){
             if(arr[left].first>arr[right].first)
             {
                 ct++;
                 temp[k++]=arr[right++]; 
             } 
             else
             {
                 ans[arr[left].second]+=ct;
                 temp[k++]=arr[left++]; 
             }
         }
         while(left<=mid){
            ans[arr[left].second]+=ct; 
            temp[k++]=arr[left++]; 
         }
         while(right <= end){
             temp[k++] = arr[right++];
         }
         
         for(int i=start, j = 0;i<=end;i++, j++){
             arr[i] = temp[j];
         }
    }

    void mergeSort(vector<pair<int,int>> &arr, vector<int> &ans, int start, int end){
       if(start==end)
       return;

       int mid = start + (end - start)/2;
       mergeSort(arr, ans, start, mid);
       mergeSort(arr, ans, mid+1, end);
       merge(arr, ans, start, mid, end);

    }
    vector<int> countSmaller(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({a[i],i});
        }

        mergeSort(arr, ans, 0,n-1);

        return ans;
    }
};