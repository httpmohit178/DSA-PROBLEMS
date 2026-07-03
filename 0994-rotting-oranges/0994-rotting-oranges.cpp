class Solution {
public:
    int r;
    int c;
    int dirx[4]={-1,1,0,0};
    int diry[4]={0,0,-1,1};
    bool valid(int row ,int col){
        return row>=0&&row<r&&col>=0&&col<c;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(grid[i][j]==2){
                q.push({i,j});
               }
            }
        }
         int timer=0;
        while(!q.empty()){
            int totalcurrrotten=q.size();
            while(totalcurrrotten--){
                int new_x=q.front().first;
                int new_y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    if(valid(new_x+dirx[i],new_y+diry[i])&&grid[new_x+dirx[i]][new_y+diry[i]]==1){
                        grid[new_x+dirx[i]][new_y+diry[i]]=2;
                        q.push({new_x+dirx[i],new_y+diry[i]});
                    }
                }
            }
             timer++;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return timer?timer-1:0;


        
    }
};