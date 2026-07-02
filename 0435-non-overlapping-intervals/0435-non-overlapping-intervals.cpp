bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),cmp);
        int count=0;
        int previousend=INT_MIN;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=previousend){
                count++;
                previousend=intervals[i][1];
            }

        }
        return n-count;
        
    }
};