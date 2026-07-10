class Solution {
public:
    int n;
    int memo[50001];
// mehnat to karni padegi lala bina mehnat ke nhi ha kuch bhi
  int getNextIndex(vector<vector<int>>&array,int l,int target){
    int r=n-1;
    int result=n+1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(array[mid][0]>=target){
            result=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return result;
  }
    int solve(vector<vector<int>>&array,int i){
        if(i>=n){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        int next=getNextIndex(array,i+1,array[i][1]);
        int taken=array[i][2]+solve(array,next);
        int nottaken=solve(array,i+1);
        return memo[i]=max(taken,nottaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // optimal maximum minium ==> hint to dp
        // vector bana lo strting point ending point and profit
        n=startTime.size();
        memset(memo,-1,sizeof(memo));
        vector<vector<int>>arr(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }

    //classical dp +memoizzeeeeeeeee
    sort(arr.begin(),arr.end());
    return solve(arr,0);


    }
};