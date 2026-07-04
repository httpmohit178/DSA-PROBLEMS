class Solution {
public: 
    int r;
    int c;
    int dirx[8]={2,2,-2,-2,1,-1,1,-1};
    int diry[8]={1,-1,1,-1,2,2,-2,-2};
    bool isvalid(int x,int y){
        return x>=0&&y>=0&&x<r&&y<c;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
      r=grid.size();
      c=grid[0].size();
      queue<pair<int,int>>q;
      if(grid[0][0]!=0){
        return false;
      }
      int step=0;
      q.push({0,0});
      while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int new_x=row+dirx[i];
            int new_y=col+diry[i];
            if(isvalid(new_x,new_y)&&grid[new_x][new_y]==step+1){
                q.push({new_x,new_y});
                step++;   
            }
        }
      }
      if(step==(r*r)-1){
        return true;
      }
      return false; 
    }
};