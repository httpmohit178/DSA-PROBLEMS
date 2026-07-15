class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // we have to find maximal square formed using 1s only

        int row=matrix.size();
        int col=matrix[0].size();

        // dp[i][j] maximal square formed till (i,j)
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int j=0;j<col;j++){
            dp[0][j]=matrix[0][j]-'0';
        }
        for(int i=1;i<row;i++){
            dp[i][0]=matrix[i][0]-'0';
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
      int maxi=0;
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            maxi=max(maxi,dp[i][j]);
        }
      }
    return maxi*maxi;
    }
    };
