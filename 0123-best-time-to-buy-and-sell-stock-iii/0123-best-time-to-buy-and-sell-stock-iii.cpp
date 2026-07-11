class Solution {
public:
  int dp[100001][2][2];
   int solve(int idx, int n,vector<int>&prices,bool canbuy,int k){
      if(idx>=n){
        return 0;
      }
      if(k==2){
        return 0;
      }
      // buy kar skte agar idx 1 ko 
      if(dp[idx][canbuy][k]!=-1){
        return dp[idx][canbuy][k];
      }
      int profit=0;
      if(canbuy){
         int take=solve(idx+1,n,prices,false,k)-prices[idx];
         int nottake=solve(idx+1,n,prices,true,k);
         profit+=max(take,nottake);
      }else{
        /// sell wala case
           int take=prices[idx]+solve(idx+1,n,prices,true,k+1);
           int nottake=solve(idx+1,n,prices,false,k);
           profit+=max(take,nottake);
      }
      return dp[idx][canbuy][k]= profit;
   }
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int k=0; // atmost 2 transcations
      memset(dp,-1,sizeof(dp));
      return solve(0,n,prices,true,k);// profit till end
    }
};