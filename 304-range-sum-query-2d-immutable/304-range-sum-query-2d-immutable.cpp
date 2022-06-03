class NumMatrix {
public:
   vector<vector<long>> l;
    NumMatrix(vector<vector<int>>& matrix) {
        long sum=0;
        
       for(int i=0;i<matrix.size();i++)
       {
           sum=0;
           vector<long> v;
           for(int j=0;j<matrix[i].size();j++)
           {
               sum=sum+matrix[i][j];
               v.push_back(sum);
           }
           
           l.push_back(v);
       }
        
//         for(int i = 0; i<l.size(); ++i){
//             for(int j = 0; j<l[i].size(); ++j){
//                 cout<<l[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++)
        {
            if(col1!=0)
                sum=sum + l[i][col2] - l[i][col1-1];
            else
                sum=sum+l[i][col2];
        }
        return sum;
    }
};