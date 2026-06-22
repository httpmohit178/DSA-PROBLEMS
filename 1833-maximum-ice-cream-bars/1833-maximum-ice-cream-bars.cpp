class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int size=costs.size();
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(auto i:costs){
         if(i<=coins){
            cnt++;
            coins-=i;
         }
         else
          break;
        }
        return cnt;
        
    }
};