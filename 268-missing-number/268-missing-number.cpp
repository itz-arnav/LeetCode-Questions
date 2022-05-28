class Solution {
public:
    
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        arr.push_back(n+1);
        n = arr.size();
        cout<<n<<endl;
        while(i < n) {
        
        int correct = arr[i];
        if(correct == n)
        {
            i++;
            continue;
        }
        if(arr[i] != arr[correct])   
        swap(arr[i], arr[correct]);
        
        else {
            i++;
        }
        }
        
        for(int i = 0; i<n; i++){
            if(arr[i] != i)
                return i;
        }
        
        return n-1;
    }
};