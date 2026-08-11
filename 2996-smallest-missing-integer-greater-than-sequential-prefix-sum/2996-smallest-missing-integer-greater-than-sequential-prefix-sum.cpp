class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,bool>mp;
        for(auto i:nums){
            mp[i]=1;
        }
        
        int n=nums.size();
        if(n==1){
            return nums[0]+1;
        }
        int sum=nums[0];
        for(int i=1;i<n;i++){
             if(nums[i]!=nums[i-1]+1){
                while(mp.find(sum)!=mp.end()){
                    sum+=1;
                }
                return sum;
             } 
             sum+=nums[i];
        }
        return sum;
    }
};