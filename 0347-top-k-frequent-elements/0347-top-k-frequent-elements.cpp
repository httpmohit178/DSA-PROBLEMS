class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            int value=i.first;
            int frequency=i.second;
            pq.push({frequency,value});
        }
        while(!pq.empty()&&k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
   return ans;
        
    }
};