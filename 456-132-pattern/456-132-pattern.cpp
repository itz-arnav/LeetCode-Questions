class Solution {
public:
     bool find132pattern(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> left(n), right(n); 
        
        left[0] = arr[0];
        for(int i = 1; i<n; i++){
          if(left[i-1] < arr[i] or arr[i-1] < arr[i]){
              left[i] = min(left[i-1], arr[i-1]);
          } 
          else{
              left[i] = left[i-1];
          }  
        }
         
        set<int> st;
        st.insert(arr[n-1]);
        for(int j = n-2; j>=0; j--){
            auto it = st.lower_bound(arr[j]);
            if(it == st.end()){
                it--;
                if(*it >= arr[j])
                    right[j] = INT_MAX;
                else
                    right[j] = *it;
            }
            else if(it == st.begin() and *it >= arr[j]){
                right[j] = INT_MAX; 
            }
            else if(it == st.begin()){
                right[j] = *it;
            }
            else{
                it--;
                right[j] = *it;
            }
            st.insert(arr[j]);
        }
        
         // for(int i = 0; i<n; i++){
         //     cout<<left[i]<<" "<<right[i]<<endl;
         // }
        for(int i = 1; i<n-1; i++){
            if(left[i] < arr[i] and right[i] < arr[i] and right[i] > left[i])
                return true;
        }
         
        return false;
    }
};