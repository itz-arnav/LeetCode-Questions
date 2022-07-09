class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
    int n = nums.size();
    if (n<4)  return ans;
    sort (nums.begin(), nums.end());
   // vector<int> quad;

    for (int i=0;i<n-3;i++){           
        
          for (int j=i+1;j<n-2;j++){
               
           // int targetX = target - nums[i] - nums[j] ;
              int front = j+1;
              int back = n-1;
              
              while (front<back){
                  
                  long long y = (long long) nums[i]+(long long)nums[j]+
                                (long long)nums[front]+(long long) nums[back];
                  
                  if ( y < target){
                      front ++;
                  }
                  else if ( y > target){
                      back--;
                  }
                  else {
                      /*
                          quad.push_back(nums[i]);
                          quad.push_back(nums[j]);
                          quad.push_back(nums[front]);
                          quad.push_back(nums[back]);
                      ans.push_back(quad);
                      quad.clear();
                      */
                      
                     ans.push_back({nums[i], nums[j], nums[front], nums[back]});
                   
                     while(front+1<back && nums[front]==nums[front+1] ) front++ ;
                     while(front<back-1 && nums[back]==nums[back-1]) back--;
                      
                      front++;
                      back--;
                  }          
              }
              while ( j+1 < n-2 &&  nums[j+1]== nums[j] ) j++;
          }
          while ( i+1 < n-3 &&  nums[i+1]== nums[i] ) i++;
         }
        return ans;
    }
};