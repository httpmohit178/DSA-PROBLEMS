class Solution {
public:
   struct cmp{
      bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first==b.first){
            return a.second>b.second;// shorter word first
        }
        return a.first<b.first; // high frequncy first
      }
   };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        map<string,int>mp;

        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto i:words){
            mp[i]++;
        }
        for(auto i:mp){
            string word=i.first;
            int frequency=i.second;
            pq.push({frequency,word});

        }
        while(!pq.empty()&&k--){
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
      
        return ans;
        
    }
};