class Solution {
public:
   int t[201][201][201];
   int mod=1e9+7;
   int solve(int idx,int gcd1,int gcd2,vector<int>&nums){
    if(idx==nums.size()){
        if(gcd1&&gcd2){
            if(gcd1==gcd2){
                return 1;
            }
        }
        return 0;
    }
      if(t[idx][gcd1][gcd2]!=-1){
        return t[idx][gcd1][gcd2];
      }
       int skip=solve(idx+1,gcd1,gcd2,nums);
       int take=solve(idx+1,__gcd(gcd1,nums[idx]),gcd2,nums);
       int take2=solve(idx+1,gcd1,__gcd(gcd2,nums[idx]),nums);
       return t[idx][gcd1][gcd2]=(((skip)%mod+(take)%mod)%mod+(take2)%mod)%mod;
   }
    int subsequencePairCount(vector<int>& nums) {
        
        int n=nums.size();
        memset(t,-1,sizeof(t));
      return   solve(0,0,0,nums);
        
    }
};