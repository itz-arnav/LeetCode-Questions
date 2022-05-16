class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        stack<int> st;
        //to reach 10^9 th fibonacci num it will take atmost 68 steps
        // q.push(1);
        long a=0,b=1,sum=0;
        //hardly size of fibonacci arr will be 67.
        while(sum<=k){
            sum=a+b,
            a=b,
            b=sum;
            st.push(sum);
        }
        
        // cout<<"finally sum is" <<sum<<endl;
        int steps = 0;
        while( !st.empty() ){
            // cout<<q.front()[0] <<endl;
            int num=st.top();
            st.pop();
            if(k >= num)   
            {
                steps+= 1;
                k -= num;
            }
            if(k == 0) 
                return steps;
            
        }
            
        return -1;
    }
};