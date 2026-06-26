class NumArray {
public:
    vector<int>arr;
   vector<int>prefix;
    NumArray(vector<int>& nums) {
        arr=nums;  
          prefix.resize(arr.size());
    prefix[0]=arr[0];
   for(int i=1;i<arr.size();i++){
    prefix[i]=arr[i]+prefix[i-1];
   }
    }
    int sumRange(int left, int right) {
        int sum=prefix[right];
        if(left>0){
            sum-=prefix[left-1];
        }
        return sum;    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */