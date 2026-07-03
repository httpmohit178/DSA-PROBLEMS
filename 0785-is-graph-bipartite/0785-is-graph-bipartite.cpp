class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //adjacenct list creation
        int n=graph.size();
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push(i);
            }
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int i:graph[node]){
                    if(color[i]==-1){
                        color[i]=(color[node]+1)%2;
                        q.push(i);
                    }else if(color[node]==color[i]){
                        return 0;
                    }
                }
            }
        }
       return true;
        
    }
};