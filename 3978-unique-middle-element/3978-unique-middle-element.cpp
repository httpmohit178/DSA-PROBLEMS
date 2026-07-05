class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int n=nums.size();
        int middle=n/2;
        if(mp[nums[middle]]==1){
            return true;
        }
        return false;
        
    }
};