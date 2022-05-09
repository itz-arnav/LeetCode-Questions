class Solution {
public:
    int partition(vector<int> &nums, int l, int r){
        int random = l + rand() % (r - l);
        swap(nums[r], nums[random]);
        int pivot = nums[r];
        int sep=l-1;
        for(int i=l; i<r; i++){
            if(nums[i]<pivot){
                sep++;
                swap(nums[i], nums[sep]);
            }
        }
        swap(nums[sep+1], nums[r]);
        return sep+1;
    }
    
    void quick_sort(vector<int> &nums, int l, int r){
        if(l>=r) return;
        
        int q = partition(nums, l, r);
        quick_sort(nums, l, q-1);
        quick_sort(nums, q+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};