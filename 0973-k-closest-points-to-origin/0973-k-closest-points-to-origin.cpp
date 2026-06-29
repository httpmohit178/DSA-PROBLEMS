class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
       priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        vector<int>curr;
        for(int i=0;i<points.size();i++){
            int firstpoint=points[i][0];
            int secondpoint=points[i][1];
            int ans=(firstpoint*firstpoint)+(secondpoint*secondpoint);
            pq.push({ans,{firstpoint,secondpoint}});  
        }
        while(!pq.empty()&&k--){
            curr.push_back(pq.top().second.first);
         curr.push_back(pq.top().second.second);
         ans.push_back(curr);
         pq.pop();
         curr.clear();
        }
        return ans;
        
    }
};