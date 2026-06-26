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
  
    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;
        //updates prefix sum form after change;
        for(int i=index;i<arr.size();i++){
            prefix[i]+=diff;
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
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */