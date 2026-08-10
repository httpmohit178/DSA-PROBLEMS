class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>arr(n+1,false);
        for(int i=1;i<n+1;i++){
            for(int k=1;k*k<=i;k++){
                if(arr[i-(k*k)]==false){
                    arr[i]=true;
                    break;
                }
            }
        }
        return arr[n];
        
    }
};