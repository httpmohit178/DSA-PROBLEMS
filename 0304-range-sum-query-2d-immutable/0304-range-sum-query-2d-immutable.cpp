class NumMatrix {
public:
vector<vector<int>>arr;
vector<vector<int>>prefix;
int row;
int col;
    NumMatrix(vector<vector<int>>& matrix) {
        arr=matrix;
        row=arr.size();
        col=arr[0].size();
       prefix.resize(row, vector<int>(col, 0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                prefix[i][j]=arr[i][j];
                if(i>0){
                    prefix[i][j]+=prefix[i-1][j];
                }
                if(j>0){
                    prefix[i][j]+=prefix[i][j-1];
                }
                if(i>0&&j>0){
                    prefix[i][j]-=prefix[i-1][j-1];
                }
            }
        } 
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        ans+=prefix[row2][col2];
        if(row1>0){
            ans-=prefix[row1-1][col2];
        }
        if(col1>0){
            ans-=prefix[row2][col1-1];
        }
        if(row1>0&&col1>0){
            ans+=prefix[row1-1][col1-1];
        }
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */