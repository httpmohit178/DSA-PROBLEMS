class Solution {
public:
  int ans=-1;
    void solve(vector<int>adj[],vector<bool>&visited,vector<bool>&path,vector<int>&depth,int currdep
    ,int node){
        visited[node]=1;
        path[node]=1;
        depth[node]=currdep;
        for(int i:adj[node]){
            if(!visited[i]){
                solve(adj,visited,path,depth,currdep+1,i);
            }else if(path[i]==1){
                ans=max(currdep-depth[i]+1,ans);
            }
        }
        path[node]=0;
        return;
    }
    int longestCycle(vector<int>& edges) {
        //We have to find the longest cycle in a graph
        // we have given a edges vector which describes how edges directed

        // First we create the adjacency list of that
        int vertex=edges.size();
        vector<int>adj[vertex];// Adjacency List
        for(int i=0;i<vertex;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        //visited vector
        vector<bool>visited(vertex,0);
        //inrecursion vector
        vector<bool>path(vertex,0);
        //Depth vector
        vector<int>depth(vertex,0);
         
         for(int i=0;i<vertex;i++){
            if(!visited[i]){
             solve(adj,visited,path,depth,0,i);
            }
         }
         return ans;
        
    }
};