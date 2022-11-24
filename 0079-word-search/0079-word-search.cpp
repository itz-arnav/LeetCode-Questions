class Solution {
public:
    bool recursion(int idx,string &word,vector<vector<char> > &board,int i,int j)

    {

        if(idx==word.size())

            return true;

        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[idx])

            return false;

        board[i][j]='$';

        bool a,b,c,d;

        a=recursion(idx+1,word,board,i+1,j);

        b=recursion(idx+1,word,board,i-1,j);

        c=recursion(idx+1,word,board,i,j+1);

        d=recursion(idx+1,word,board,i,j-1);

        board[i][j]=word[idx];

        if(a || b || c || d)    return true;

        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++)

        {

            for(int j=0;j<board[i].size();j++)

            {

                bool x=false;

                if(board[i][j]==word[0])

                    x=recursion(0,word,board,i,j);

                if(x)

                    return true;

            }

        }

        return false;

    }
};