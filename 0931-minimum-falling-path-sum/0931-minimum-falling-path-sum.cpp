class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
       vector<vector<int>>dp(row,vector<int>(col,-1));
       // dp[i][j] represnets minimum cost required from any strt row to end row

       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==0){
                dp[0][j]=matrix[0][j];
            }else{
                int up=1e9;
                if(i>0){
                    up=matrix[i][j]+dp[i-1][j];
                }
                int upperleft=1e9;
                if(i>0&&j>0){
                    upperleft=matrix[i][j]+dp[i-1][j-1];
                }
                int upperright=1e9;
                if(j<col-1){
                    upperright=matrix[i][j]+dp[i-1][j+1];
                }
                dp[i][j]=min(upperleft,min(up,upperright));
            }
        }
       }
        int mini=1e9;
        for(int j=0;j<col;j++){
            mini=min(dp[row-1][j],mini);
        }
        return mini;
    }
};