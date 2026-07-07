class Solution {
public:

   bool checkpossible(int speed,double hour,vector<int>&dis){
        double totalhours=0;
        for(int i=0;i<dis.size()-1;i++){
            totalhours+=ceil((1.0*dis[i])/speed);
        }
        totalhours+=(1.0*dis[dis.size()-1]/speed);
        return totalhours<=hour;
   }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int left=1;
        int right=1e7;
      int   ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(checkpossible(mid,hour,dist)){
                ans=mid;
                right=mid-1;

            }else{
                left=mid+1;
            }
        }
        return ans;
        
    }
};