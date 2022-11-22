class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int nearestExit(vector<vector<char>>&maze, vector<int>&e) {
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        maze[e[0]][e[1]]='+';
        int moves = 1;
        
        while(!q.empty()){
           int n = q.size();
           for(int l=0;l<n;l++){
           int i = q.front().first;
           int j = q.front().second;
            q.pop(); 
            for(int k=0;k<4;k++){
               int x = i+dx[k];
               int y = j+dy[k];
             if(x>=0 && y>=0 && x<maze.size() && y<maze[0].size() && maze[x][y]=='.'){
             if(x==0 || y==0 || x==maze.size()-1 || y==maze[0].size()-1) return moves;
                maze[x][y] = '+';
                q.push({x,y});
              }
            }
           }
           moves++; 
        }
     return -1;
    }
};