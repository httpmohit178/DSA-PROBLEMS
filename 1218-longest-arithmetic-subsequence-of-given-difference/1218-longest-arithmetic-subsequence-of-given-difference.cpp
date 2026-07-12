class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        /// we have to find the long arithmetic subsquecne with a difference given
       int n=arr.size();
        // simple LIS 
        vector<int>dp(n,1);
        // dp[i]==> represents longest arithmetic subsqucence till i with a difference given
       unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
             int element=arr[i]-difference;
             if(mp.find(element)!=mp.end()){
            
                dp[i]=mp[element]+1;
             }
             mp[arr[i]]=dp[i];
        }
        int ans=*max_element(dp.begin(),dp.end());
        return ans;
        
        
    }
};