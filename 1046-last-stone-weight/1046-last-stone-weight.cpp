class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int maxi1=pq.top();
            pq.pop();
            int maxi2=abs(maxi1-pq.top());
            pq.pop();
            if(maxi2) pq.push(maxi2);
        }
        return  !pq.empty()?pq.top():0;
        
    }
};