class Solution {
public:
   static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1] ;//sort it in descending order
        }
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int ans=0;
        int maxend=0;
        sort(intervals.begin(),intervals.end(),cmp);
        for(auto&it:intervals){
          
            if(it[1]>maxend){
                ans++;
                maxend=max(maxend,it[1]);
            }
        }
        return ans;

        
    }
};