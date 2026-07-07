class Solution {
public:
   bool canpossible(int balls,int force, vector<int>&position){
    int count =1;
    int currposition=position[0];
    for(int i=1;i<position.size();i++){
        if(position[i]-currposition>=force){
            count++;
            currposition=position[i];
            if(count==balls)
                return true;
        }
    }
    return false;
   }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();  //////// easy paesy --->>> kill 
      sort(begin(position),end(position));
      int l=1;
      int r=position[n-1]-position[0];
      int ans=0;
      while(l<=r){
        int mid=l+(r-l)/2;
        if(canpossible(m,mid,position)){
             ans=mid;
           l=mid+1;

        }else{
           r=mid-1;
        }
      }
      return ans;
        
    }
};