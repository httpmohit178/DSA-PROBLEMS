class Solution {
public:
    int timeRequiredToBuy(vector<int>& ti, int k) {
         int time = 0;
for(int i= 0;i<=k;i++){
time+=min(ti[i],ti[k]);
}   
for(int i=k+1;i<ti.size();i++){
    time+=min(ti[i],ti[k]-1);
}    
return time;
        
    }
};