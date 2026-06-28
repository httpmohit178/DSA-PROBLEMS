class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        int n=gifts.size();
        //max heap
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(gifts[i]);
        }
        long long sum=0;
        while(k--&&!pq.empty()){
            int num=sqrt(pq.top());
            pq.push(num);
            pq.pop();
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
      
        return sum;
    }
};