class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size();
        long long maxi=*max_element(nums.begin(),nums.end());
        long long count=0;
        long long start=0;
        long long end=0;
        long long total=0;
        while(end<n){
            if(nums[end]==maxi){
                count++;
            }
            while(count==k){
                total+=(n-end);
                if(nums[start]==maxi) count--;
                start++;
            }
            end++;
        }
        return total;
        
    }
};