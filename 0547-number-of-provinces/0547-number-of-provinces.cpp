class Solution {
public:
   void bfs(int node,vector<int>AdjMat[],int vertex,vector<bool>&visited){
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int n=q.front();
        q.pop();
        visited[n]=true;
        for(auto v:AdjMat[n]){
            if(!visited[v]){
            visited[v]=true;
            q.push(v);
            }
        }
    }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertex=isConnected.size();
        vector<int>AdjMat[vertex];
        for(int i=0;i<vertex;i++){
            for(int j=0;j<vertex;j++){
                if(isConnected[i][j]==1){
                    AdjMat[i].push_back(j);
                    AdjMat[j].push_back(i);
                }
            }
        }
        vector<bool>visited(vertex,false);
        int count=0;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                count++;
                bfs(i,AdjMat,vertex,visited);
                
            }
        }
        return count;
        
    }
};