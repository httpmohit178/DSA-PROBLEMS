class Solution {
public:
   typedef long long ll;
    bool canpossible( ll maxi,vector<int>&candies,long long k){
       ll count=0;
       for(auto i:candies){
         count+=i/maxi;
    
       }
        return  count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        // easy peasy solution 
        ll n=candies.size();
        ll l=1;
        ll r=*max_element(candies.begin(),candies.end());
        ll ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(canpossible(mid,candies,k)){
                ans=mid;
                l=mid+1;
            }else{
               r=mid-1;
            }
        }
        return ans;
    }
};