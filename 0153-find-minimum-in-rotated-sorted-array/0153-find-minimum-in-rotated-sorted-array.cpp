class Solution {
public:

   /// sorted array so binary search
   // TC=O(LOG(N))
    int findMin(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[r]){
                l=mid+1;
            }else{
                r=mid;
            }
        } 
        return arr[r];       
    }
    
};