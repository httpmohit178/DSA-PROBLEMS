class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int start=intervals[0][0];
        int previous=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=previous){
                int maxi=max(previous,intervals[i][1]);
                previous=maxi;
                ans.pop_back();
                ans.push_back({start,maxi});
            }else{
                ans.push_back(intervals[i]);
                start=intervals[i][0];
                previous=intervals[i][1];
            }
        }
        return ans;
    }
};