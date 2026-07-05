class Solution {
public:
    void solve(int sr,int sc,vector<vector<int>>&image,vector<vector<int>>&ans,int color,int initialcolor,int deltax[],int deltay[]){
        ans[sr][sc]=color;
        int row=image.size();
        int col=image[0].size();
        for(int i=0;i<4;i++){
            int new_r=sr+deltax[i];
            int new_y=sc+deltay[i];
            if(new_r>=0&&new_r<row&&new_y>=0&&new_y<col&&image[new_r][new_y]==initialcolor&&ans[new_r][new_y]!=color){
                solve(new_r,new_y,image,ans,color,initialcolor,deltax,deltay);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size();
        int c=image[0].size();
        vector<vector<int>>ans=image;
        int initialcolor=image[sr][sc];
        int deltax[4]={-1,1,0,0};
        int deltay[4]={0,0,-1,1};
        solve(sr,sc,image,ans,color,initialcolor,deltax,deltay);
        return ans;
        
    }
};