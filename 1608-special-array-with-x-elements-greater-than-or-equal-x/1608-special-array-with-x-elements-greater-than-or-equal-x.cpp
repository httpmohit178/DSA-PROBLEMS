class Solution {
public:
   int canpossible(int count,vector<int>&arr){
    int initialcount=0;
    for(auto &i:arr){
        if(i>=count){
            initialcount++;
        }
    }
    return initialcount;
   
   }
    int specialArray(vector<int>& nums) {
        //optimal using binary search approach I can do it
        int n=nums.size();
    // ek esa number chaiye jisse array ke eleements utne hi times greater than ya equal to ho
    int l=0;
    int r=n;
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        int count=canpossible(mid,nums);
         if(count==mid){
           return mid;
         }else if(count>mid){
            l=mid+1;
         }else{
            r=mid-1;
         }
    }
 return -1;  
    }
};