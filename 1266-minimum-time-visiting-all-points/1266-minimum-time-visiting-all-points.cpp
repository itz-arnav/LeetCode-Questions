class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& arr) {
        int x = arr[0][0];
        int y = arr[0][1];
        int n = arr.size();
        int ct = 0;
        for(int i = 1; i<n; ++i){
            while(x != arr[i][0] or y != arr[i][1]){
                if(x == arr[i][0]){
                    if(y > arr[i][1])
                        y--;
                    else
                        y++;
                }
                else if(y == arr[i][1]){
                    if(x < arr[i][0]){
                        x++;
                    }
                    else
                        x--;
                }
                else{
                    if(x < arr[i][0]){
                        x++;
                    }
                    else{
                        x--;
                    }
                    if(y < arr[i][1]){
                        y++;
                    }
                    else
                        y--;
                }
                ct++;
            }
        }
        return ct;
    }
};