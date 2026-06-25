class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int end=0;
        int count=0;
        unordered_map<int,int>mp;
        while(end<n){
            mp[nums[end]]++;
            while(mp[nums[end]]>k){
                mp[nums[start]]--;
                start++;
            }
            count=max(count,end-start+1);
            end++;
        }
        return count;
        
    }
};