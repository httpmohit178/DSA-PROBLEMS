class Solution {
public:
//// sorted ha toh pakka binary search bol rha ha
// to solve in O(LOG(N)) THATS WHY BINARY SEARCH

// SIMPLE INTUTION IS THAT MUJHE LEFT MOST WALA TARGET CHAIYE AND RIGHTMOST WLA TARGET
   int findleftmost(vector<int>&nums,int target){
    int l=0;
    int r=nums.size()-1;
    int leftmost=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==target){
            leftmost=mid;
            r=mid-1;
        }
        else if(nums[mid]>target){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return leftmost;
   }
      int findrightmost(vector<int>&nums,int target){
    int l=0;
    int r=nums.size()-1;
    int leftmost=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==target){
            leftmost=mid;
            l=mid+1;
        }
        else if(nums[mid]>target){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return leftmost;
   }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftmost=findleftmost(nums,target);
        int rightmost=findrightmost(nums,target);
        return{leftmost,rightmost};
        
    }
};