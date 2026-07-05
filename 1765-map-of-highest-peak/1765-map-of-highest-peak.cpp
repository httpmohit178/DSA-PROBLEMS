class Solution {
public:
    int r;
    int c;
    int dirx[4]={-1,0,0,1};
    int diry[4]={0,-1,1,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
          r=mat.size();
        c=mat[0].size();
        // bfs mar do easy paesy
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>ans(r,vector<int>(c,0));
        vector<vector<int>>visited(r,vector<int>(c,0));
        // sare one phhle andar daal do
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    q.push({{i,j},0}); 
                    visited[i][j]=1;
                    //multisource bfs
                }else{
                    visited[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dis=q.front().second;
            q.pop();
              ans[x][y]=dis;
            for(int i=0;i<4;i++){
                int new_x=x+dirx[i];
                int new_y=y+diry[i];
                
                if(new_x>=0&&new_y>=0&&new_x<r&&new_y<c&&!mat[new_x][new_y]&&!visited[new_x][new_y]){

                    visited[new_x][new_y]=1;
                    q.push({{new_x,new_y},dis+1});
                }
            }
          
        }
        return ans;
        
    }
        
    
};