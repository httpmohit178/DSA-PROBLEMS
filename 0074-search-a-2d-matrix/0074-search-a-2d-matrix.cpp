class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // best approach usinh two pointers
        int i=0;
        int j=matrix[0].size()-1;
        while(i<=matrix.size()-1&&j>=0){
            if(matrix[i][j]<target){
                i++;
            }else if(matrix[i][j]>target){
                j--;
            }
            else if(matrix[i][j]==target){
            

                return true;
            }
        }
        return false;
        
    }
};