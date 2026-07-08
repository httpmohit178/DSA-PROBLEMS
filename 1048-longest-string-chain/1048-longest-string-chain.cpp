class Solution {
public:
int dp[1001][1001];
bool checkpre(string &a, string &b) {
    if (b.size() != a.size() + 1)
        return false;

    int i = 0, j = 0;

    while (j < b.size()) {
        if (i < a.size() && a[i] == b[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }

    return i == a.size();
}
    int solve(int size,vector<string>&words,int prev_index,int curr_index ){
        if(curr_index==size){
            return 0;
        }
        // when we can take the next string into the length if it is predecessor of previous
        if(prev_index!=-1&&dp[curr_index][prev_index]!=-1){
            return dp[curr_index][prev_index];
        }
        int take=0;
        if(prev_index==-1||checkpre(words[prev_index],words[curr_index])){
            take=1+solve(size,words,curr_index,curr_index+1);

        }
        // when we not take that index
        int nottake=solve(size,words,prev_index,curr_index+1);
        if(prev_index!=-1){
            dp[curr_index][prev_index]=max(take,nottake);
        }
        return max(take,nottake);
    }
    int longestStrChain(vector<string>& words) {
        /// sabse pheli baat ha darne ka nhi easy hoti ha chize bus ques par dhyan do may it takes to long
        // but u will definetily achieve in one day u can do it 
        memset(dp,-1,sizeof(dp));
        sort(words.begin(), words.end(), [](string &a, string &b){
    return a.size() < b.size();
});
        int n=words.size();
     return    solve(n,words,-1,0);
        
    }
};