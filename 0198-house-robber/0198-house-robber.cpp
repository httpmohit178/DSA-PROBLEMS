class Solution {
public:
    int rob(vector<int>& nums) {
        
        /// Hume karni ha chori vo bhi jyada se jyada paisa chaiya paisa hi sab kkuch ha
        // simple easy
        int n=nums.size();
        vector<int>dp(n+1,0);

        // dp represents dp[i]==>>>> utne ghar tak kitni chori hui maximum
        //agar 0 ghar ha toh
        dp[0]=0;
        //agar 1 ghar ha toh
        dp[1]=nums[0];

        for(int i=2;i<=n;i++){
            int steal= nums[i-1]+dp[i-2];
            int skip =dp[i-1];
            dp[i]=max(steal,skip);
        }
        return dp[n];

    }
};